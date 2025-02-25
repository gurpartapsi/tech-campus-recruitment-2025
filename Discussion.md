*Solutions Considered*: 
1. *Memory Mapping*: One approach considered was to use memory-mapped files to load sections of the large log file into memory. This method can be efficient for random access but could be complex to implement for sequential log retrieval.
2. *Parallel Processing*: Another approach was to split the log file into smaller chunks and process them in parallel. While this can speed up the process, it introduces additional complexity in synchronizing and merging the results.
3. *Indexing*: Creating an index for the log file based on dates could allow for faster retrieval. This would involve an initial preprocessing step to build the index, but would make subsequent searches much faster.

*Final Solution Summary*: 
The chosen solution was to use a simple file stream method to read the log file line by line and filter the entries based on the specified date. This approach was selected because:
- It is straightforward and easy to implement.
- It efficiently handles the large file size by processing one line at a time, which minimizes memory usage.
- It meets the performance requirements for the given constraints, providing a good balance between simplicity and efficiency.

*Steps to Run*: 
1. *Save the Code*: Save the provided C++ code in a file named extract_logs.cpp and place it in ..tech-campus-recruitment-2025\src.
2. *Open Command Prompt*: Open the command prompt and navigate to the directory ..tech-campus-recruitment-2025\src using the following command:
   sh
   cd C:\Users\Karthik\tech-campus-recruitment-2025\src
   
3. *Compile the Code*: Compile the C++ code using the following command:
   sh
   g++ extract_logs.cpp -o extract_logs
   
4. *Run the Script*: Execute the compiled program with the specified date (e.g., 2024-12-01) using the following command:
   sh
   ./extract_logs 2024-12-01
   

5. *Output*: The log entries for the specified date will be saved to a file named output/output_2024-12-01.txt in the C:\Users\Karthik\tech-campus-recruitment-2025\output directory.
