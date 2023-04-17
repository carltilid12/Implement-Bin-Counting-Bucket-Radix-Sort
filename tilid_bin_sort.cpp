/*
Carl Christian G. Tilid BSCS II CSC124
Implement the linear sorting algorithms as described in Slide CSC124_L02c_Sorting.  
Just like the previous exercises experiment on different input sizes and graph the 
input size versus the time it takes to run the sorting algorithms. 
Do these algorithms really run at O(n) time?  Submit your source code and excel file.
*/

#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;


int main(){
    srand(time(0));
    //Initialize size and the array
    clock_t time_req;
    int sizearr = 20;
    int arr[sizearr];
    int bin[sizearr]; //Default Bin sort uses an array that has no duplicates
    int i = 0;
    int num = 0;

    //Making a non duplicating array
    for(i=0; i<sizearr; i++){
        arr[i] = i;
    }
    random_shuffle(&arr[0], &arr[sizearr]);
    //Display Array and reusing the Bin by assigning Bin to zero
    for(i=0; i<sizearr; i++){
        cout << arr[i] << " ";
        bin[i] = 0;

    }
    cout << endl;
    //Start Timer
    time_req = clock();

    int index; //Creating Index
    //Checking arr and marking the bin as 1 if the index is present
    for(i=0; i<sizearr; i++){
        index = arr[i];
        bin[index] = 1;
    }
    //Displaying sorted array by displaying the indexes if Bin
    for(i=0; i<sizearr; i++){
        if(bin[i] == 1){
            cout << i << " ";
        }
    }
    time_req = clock() - time_req;

    cout << endl;
    cout << "The time it took = " << (float)time_req/CLOCKS_PER_SEC << endl;
    return 0;
}
