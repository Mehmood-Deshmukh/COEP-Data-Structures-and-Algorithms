#!/bin/bash

test_cases_dir="./Tests"
results_dir="./Results"
bubble_sort_dir="${results_dir}/bubble_sort"
selection_sort_dir="${results_dir}/selection_sort"
insertion_sort_dir="${results_dir}/insertion_sort"
quick_sort_dir="${results_dir}/quick_sort"
heap_sort_dir="${results_dir}/heap_sort"

bubble_sort_executable="./bubble_sort"
selection_sort_executable="./selection_sort"
insertion_sort_executable="./insertion_sort"
quick_sort_executable="./quick_sort"
heap_sort_executable="./heap_sort"

mkdir -p "$results_dir"
mkdir -p "$bubble_sort_dir"
mkdir -p "$selection_sort_dir"
mkdir -p "$insertion_sort_dir"
mkdir -p "$quick_sort_dir"
mkdir -p "$heap_sort_dir"

sorting_algorithms=("bubble_sort" "selection_sort" "insertion_sort" "quick_sort" "heap_sort")
test_cases_order=("100" "200" "500" "1000" "2000" "5000" "10000" "20000" "50000")

run_command_and_time() {
 local command="$1"
 local start_time=$(date +%s%N)
 eval "$command" > /dev/null
 local end_time=$(date +%s%N)
 local duration=$((end_time - start_time))
 echo "Total Milliseconds: $(echo "scale=8; $duration / 1000000" | bc)"
}

for sorting_algorithm in "${sorting_algorithms[@]}"; do
 for test_case_order in "${test_cases_order[@]}"; do
   echo "Running $sorting_algorithm with test case $test_case_order"
   test_case_file="${test_cases_dir}/${test_case_order}.txt"
   echo "Test case file: $test_case_file"

   if [ "$sorting_algorithm" = "bubble_sort" ]; then
     bubble_sort_output_file="${bubble_sort_dir}/${test_case_order}.txt"
     run_command_and_time "cat $test_case_file | $bubble_sort_executable $bubble_sort_output_file" > "$bubble_sort_dir/${test_case_order}.txt"
   elif [ "$sorting_algorithm" = "selection_sort" ]; then
     selection_sort_output_file="${selection_sort_dir}/${test_case_order}.txt"
        run_command_and_time "cat $test_case_file | $selection_sort_executable $selection_sort_output_file" > "$selection_sort_dir/${test_case_order}.txt"
    elif [ "$sorting_algorithm" = "insertion_sort" ]; then
        insertion_sort_output_file="${insertion_sort_dir}/${test_case_order}.txt"
        run_command_and_time "cat $test_case_file | $insertion_sort_executable $insertion_sort_output_file" > "$insertion_sort_dir/${test_case_order}.txt"
    elif [ "$sorting_algorithm" = "quick_sort" ]; then
        quick_sort_output_file="${quick_sort_dir}/${test_case_order}.txt"
        run_command_and_time "cat $test_case_file | $quick_sort_executable $quick_sort_output_file" > "$quick_sort_dir/${test_case_order}.txt"
    elif [ "$sorting_algorithm" = "heap_sort" ]; then
        heap_sort_output_file="${heap_sort_dir}/${test_case_order}.txt"
        run_command_and_time "cat $test_case_file | $heap_sort_executable $heap_sort_output_file" > "$heap_sort_dir/${test_case_order}.txt"
    fi
 done
done