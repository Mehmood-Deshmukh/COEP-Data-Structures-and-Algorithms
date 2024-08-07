import os
import pandas as pd
import matplotlib.pyplot as plt

results_dir = 'Results'

test_cases_order = ['1k', '5k', '10k', '50k', '100k', '500k', '1m']

def extract_milliseconds(file_path):
    with open(file_path, 'r', encoding='utf-16') as file:
        lines = file.readlines()
        for line in lines:
            if 'TotalMilliseconds' in line:
                parts = line.split(':')
                return float(parts[1].strip())
    return None

data = {test_case: {} for test_case in test_cases_order}


for algo_dir in os.listdir(results_dir):
    algo_path = os.path.join(results_dir, algo_dir)
    if os.path.isdir(algo_path):
        for result_file in os.listdir(algo_path):
            test_case = os.path.splitext(result_file)[0]
            if test_case in test_cases_order:
                result_path = os.path.join(algo_path, result_file)
                milliseconds = extract_milliseconds(result_path)
                if milliseconds is not None:
                    data[test_case][algo_dir] = milliseconds

df = pd.DataFrame(data).transpose()
df = df.loc[test_cases_order]

plt.figure(figsize=(10, 6))
for algo in df.columns:
    plt.plot(df.index, df[algo], marker='o', label=algo)

plt.xlabel('Test Case')
plt.ylabel('Time (ms)')
plt.title('Sorting Algorithm Performance')
plt.legend()
plt.grid(True)
plt.xticks(rotation=45)
plt.tight_layout()


plt.savefig('sorting_algorithms_performance.png')
plt.show()
