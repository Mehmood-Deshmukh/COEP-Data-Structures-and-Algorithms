import os
import pandas as pd
import matplotlib.pyplot as plt

results_dir = './Results'
test_cases_order = ["100", "200", "500", "1000", "2000", "5000", "10000", "20000", "50000"]

def extract_milliseconds(file_path):
   with open(file_path, 'r', encoding='utf-8') as file:
       lines = file.readlines()
       for line in lines:

           if 'Total Milliseconds' in line:
               parts = line.split(':')
               return float(parts[1].strip())
   return None

data = {test_case: {} for test_case in test_cases_order}

for algo_dir in ['selection_sort', 'bubble_sort', 'insertion_sort', 'merge_sort', 'quick_sort', 'heap_sort']:
   algo_path = os.path.join(results_dir, algo_dir)
   if os.path.isdir(algo_path):
       for result_file in os.listdir(algo_path):
           test_case = os.path.splitext(result_file)[0]
           if test_case in test_cases_order:
               result_path = os.path.join(algo_path, result_file)
               milliseconds = extract_milliseconds(result_path)
               print(f'{algo_dir} - {test_case}: {milliseconds} ms')
               if milliseconds is not None:
                   data[test_case][algo_dir] = milliseconds

df = pd.DataFrame(data).transpose()
df = df.loc[test_cases_order]

plt.figure(figsize=(10, 6))
for algo in df.columns:
   plt.plot(df.index, df[algo], marker='o', label=algo)

plt.xlabel('Array Size')
plt.ylabel('Time (ms)')
plt.title('Comparative Performance of Sorting Algorithms')
plt.legend()
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.xticks(rotation=45)
plt.tight_layout()
plt.savefig('comparative_sort_performance.png')