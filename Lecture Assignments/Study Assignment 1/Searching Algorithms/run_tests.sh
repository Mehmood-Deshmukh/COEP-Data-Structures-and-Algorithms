#!/bin/bash


test_cases_dir="./Tests"
results_dir="./Results2"
linear_search_dir="${results_dir}/linear_search"
binary_search_dir="${results_dir}/binary_search"

linear_search_executable="./linear_search"
binary_search_executable="./binary_search"

mkdir -p "$results_dir"
mkdir -p "$linear_search_dir"
mkdir -p "$binary_search_dir"

test_cases_order=("5" "10" "20" "100" "500" "1000" "5000" "10000" "20000" "50000")

run_command_and_time() {
    local command=$1
    local start_time=$(date +%s%N)  
    eval "$command" > /dev/null  
    local end_time=$(date +%s%N)  
    local duration=$((end_time - start_time))
    echo "scale=8; $duration / 1000000" | bc  
}


for test_case in "${test_cases_order[@]}"; do
    unsorted_file="${test_cases_dir}/${test_case}.txt"
    sorted_file="${test_cases_dir}/${test_case}_sorted.txt"

    
    if [[ -f "$unsorted_file" ]]; then
        linear_search_command="cat \"$unsorted_file\" | \"$linear_search_executable\""
        linear_search_time=$(run_command_and_time "$linear_search_command")
        echo "Linear Search Time for $test_case: ${linear_search_time} ms"

        
        echo "TotalMilliseconds: ${linear_search_time}" > "${linear_search_dir}/${test_case}.txt"
    else
        echo "Unsorted test case file $unsorted_file does not exist."
    fi

    
    if [[ -f "$sorted_file" ]]; then
        binary_search_command="cat \"$sorted_file\" | \"$binary_search_executable\""
        binary_search_time=$(run_command_and_time "$binary_search_command")
        echo "Binary Search Time for $test_case: ${binary_search_time} ms"

        echo "TotalMilliseconds: ${binary_search_time}" > "${binary_search_dir}/${test_case}.txt"
    else
        echo "Sorted test case file $sorted_file does not exist."
    fi
done

echo "Test case execution completed."
