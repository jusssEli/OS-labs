//Implementation of the bankers algorithm by Elijah Rogers
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using std::cout; using std::endl;

const int resources = 3; //m
const int processes = 5; //n

bool safeCheck(int processArr[],int available[],int max[][resources],int allocation[][resources]);

int main(){
    // Data Structures for the Banker's Algorithm
    int processArr[] = {0, 1, 2, 3, 4};
    int max[processes][resources];
    int allocation[processes][resources];
    int available[resources];
    //Attempting to open file and if not, exit the program
    std::fstream theFile("instance.txt");
    if(!theFile){
        cout << "File dont open buckaroo, Im quitting on you now." << endl;
        return EXIT_FAILURE;
    }

    // Readin in input from file
    //inputing the allocation & max values into the 2d arrays
    for(int i = 0; i < processes; ++i){
        for(int j = 0; j < resources; ++j)
            theFile >> allocation[i][j];
        for(int j = 0; j < resources; ++j)
            theFile >> max[i][j];
        
        //allows first row to contain the resources while the rest is max and allocation
        if(i == 0)
            for(int j =0; j < resources; ++j)
                theFile >> available[j];
    }
    //The for loop will print all the resources allocated in the 2d array (matrix)
    cout << "Resources Allocated: ";
    for(int i = 0; i < processes; ++i)
        for (int j = 0; j < resources; ++j) 
            cout << allocation[i][j] << ' ';
    cout << endl;
    //The for loop will print the max resources available in the 2d array (matrix)
    cout << "Max Resources: ";
    for(int i = 0; i < processes; ++i)
        for (int j = 0; j < resources; ++j) 
            cout << max[i][j] << ' ';
    cout << endl;
    //The for loop will print all the available resources in the 2d array (matrix)
    cout << "Available Resources: ";
    for(int i = 0; i < resources; ++i)
        cout << available[i] << ' ';
    cout << endl;

    //Checking for safety
    safeCheck(processArr, available, max, allocation);

}
bool safeCheck( int processArr[], int available[], int max[][resources], 
                int allocation[][resources])
{
    //calculate the need
    int need[processes][resources];
    for (int i = 0; i < processes; ++i) {
        for (int j = 0; j < resources; ++j) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    //initializing a boolean array where all elements initialized to false
    bool finish[processes] = {0};
    //storage of the safe sequence
    int safety[processes];
    
    //copy available resources
    int work[resources];
    for(int i = 0; i < resources; ++i)
        work[i] = available[i];

    //while process isnt finished or not in safe state
    int counter = 0; //jus a counter variable
    while(counter < processes){
        //find unifinished process that needs can be satisfied
        bool found = false;
        for (int p = 0; p < processes; ++p){
            if(finish[p] == 0){
                //check if resources < work
                int j;
                for (j = 0; j < resources; ++j)
                    if(need[p][j] > work[j])
                        break;
                //if needs satisfied
                if(j == resources)
                {
                    //add allocation to work (free resources)
                    for (int k = 0 ; k < resources ; k++)
                        work[k] += allocation[p][k];

                    // Add process to safe sequence.
                    safety[counter++] = p;
 
                    // Mark process finished
                    finish[p] = 1;
 
                    found = true;
                }
            }
        }
        // If next process in safe sequence isnt found
        if (found == false){
            cout << "MAYDAY MAYDAY, SYSTEN UNSAFE. \nEVACUATE!!!!!!!!!!!!!!!!!!\n";
            return false;
        }

    }
    // If system is in safe state, print safe state
    cout << "THE UMP'S CALL IS ... SAFE!!!!!.\nSafe"
         " sequence is: ";
    for (int i = 0; i < processes ; i++)
        cout << safety[i] << " ";
    cout << endl;
    return true;
}
