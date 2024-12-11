#!/bin/bash

sizes=(100 200 500 1000 2000 5000 10000 20000 50000)


for size in "${sizes[@]}"; do

    output_file="${size}.txt"
    

    ./randomNumberGenerator > "$output_file" <<EOF
$size $size
EOF


    if [[ -f "$output_file" ]]; then
        echo "Generated file $output_file with array size $size"
    else
        echo "Failed to generate file $output_file for array size $size"
    fi
    mkdir -p Tests
    mv "$output_file" Tests/
done
