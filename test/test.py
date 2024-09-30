import requests
import json
import os

def read_file(filename):
    with open(filename, 'r') as file:
        return file.read()

def combine_c_files(header_file, logic_file, main_file):
    header = read_file(header_file)
    logic = read_file(logic_file)
    main = read_file(main_file)

    # Remove any #include statements for the other files
    logic = logic.replace('#include "header.h"', '')
    main = main.replace('#include "logic.c"', '')

    # Combine the files
    combined_code = f"{header}\n\n{logic}\n\n{main}"
    return combined_code

def execute_c_code(code, url):
    headers = {
        'Content-Type': 'application/json'
    }
    data = {
        'code': code
    }
    response = requests.post(url, headers=headers, data=json.dumps(data))
    return response.json()

if __name__ == "__main__":
    # Specify the file paths
    header_file = 'header.h'
    logic_file = 'logic.c'
    main_file = 'main.c'

    # Combine the C files
    combined_code = combine_c_files(header_file, logic_file, main_file)



    # Send the combined code to the local server
    result = execute_c_code(combined_code, 'http://localhost:3000/execute-c')

    # Print the result
    print("Execution result:")
    if 'output' in result:
        print("Execution successful. Output:")
        print(result['output'])
    elif 'error' in result:
        print("Execution failed. Error:")
        print(result['error'])
    else:
        print("Unexpected response:", result)