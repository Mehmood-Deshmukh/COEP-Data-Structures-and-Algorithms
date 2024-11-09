#!/bin/bash

sizes=(5 10 20 100 500 1000 5000 10000 20000 50000)


for size in "${sizes[@]}"; do

    output_file="${size}.txt"
    sorted_output_file="${size}_sorted.txt"
    

    ./randomNumberGenerator > "$output_file" <<EOF
$size $size
EOF


    if [[ -f "$output_file" ]]; then
        echo "Generated file $output_file with array size $size"

   
        sort -n "$output_file" > "$sorted_output_file"
        echo "Generated sorted file $sorted_output_file"
    else
        echo "Failed to generate file $output_file for array size $size"
    fi
done
