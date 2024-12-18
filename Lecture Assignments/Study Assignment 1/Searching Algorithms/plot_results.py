import os
import pandas as pd
import matplotlib.pyplot as plt

results_dir = './Results'
test_cases_order = ['5', '10', '20', '100', '500', '1000', '5000', '10000', '20000', '50000']


def extract_milliseconds(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        lines = file.readlines()
        for line in lines:
            if 'TotalMilliseconds' in line:
                parts = line.split(':')
                return float(parts[1].strip())
    return None


data = {test_case: {} for test_case in test_cases_order}

for algo_dir in ['linear_search', 'binary_search']:
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
print(df)


plt.figure(figsize=(10, 6))
for algo in df.columns:
    plt.plot(df.index, df[algo], marker='o', label=algo)


plt.ylim(0, 20)  


plt.xlabel('Array Size')
plt.ylabel('Time (ms)')
plt.title('Comparative Performance of Linear Search and Binary Search')


plt.legend()
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.xticks(rotation=45)
plt.tight_layout()


plt.savefig('comparative_search_performance.png')
