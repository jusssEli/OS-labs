
# Assignment 2
By Elijah Rogers

## Execution
Before running the program, you will need to compile it. Simply run `g++ bankersAlgo.cpp ` in the terminal. 
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
The project was to implement the banker's alorithm through a table provided, but loaded in a separate text file. The file consisted of processes, allocated memory, maximum number of resources and the available resources. A fixed number of processes and resources were also given. The file needed to be read and the code to successfully implement the bankers algorithm to determine if the given table was in a safe state or not.

## Now, What Did We Learn
I found online resources to compare with Dr. Guam's slides from class to help implement the algorithm easier. I learned to use a 2d array to implement a matrix within c++ to make a table as well. The most difficult part as remembering how I needed to read in from a file and store the contents within the table.
