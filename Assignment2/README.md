
# Assignment 2
By Elijah Rogers

## Execution
Before running the program, you will need to compile it. Simply run `g++ bankers.cpp ` in the terminal. 
Once you compile it, you should have a singular output file `a.out` which you can subsequently run `./a.out`

## Output
![image](https://github.com/user-attachments/assets/fb655376-1b8e-473b-8314-a1c362b865b1)

## Data Table
Data table provided:
| Process | Allocation | Max | Available |
| --- | --- | --- | --- |
| P0 | 0 1 0 | 7 5 3 | 3 3 2 |
| P1 | 2 0 0 | 3 2 2 | |
| P2 | 3 0 2 | 9 0 2 | |
| P3 | 2 1 1 | 2 2 2 | |
| P4 | 0 0 2 | 4 3 3 | |

In instance.txt, the table was created by using spaces as a separation key.

## Explaination
The project was to implement the banker's alorithm through a table provided, but loaded in a separate text file. The file consisted of processes, allocated data, maximum number of resources and the available resources. A fixed number of processes and resources was also given. The file needed to be read in and the code to successfully implement the bankers algorithm to determine if the given table was in a safe state or not.

## Problems and Lessons Learned
