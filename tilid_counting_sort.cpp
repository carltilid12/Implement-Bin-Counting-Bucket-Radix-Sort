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
    int bin[sizearr];
    int i = 0;
    int num = 0;

    //Generate Random Array with dupes and setting all bin to 0
    for(i=0; i<sizearr; i++){
        arr[i] = rand() % sizearr;
        bin[i] = 0;
    }

    //Display Array 
    for(i=0; i<sizearr; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    //Start Timer
    time_req = clock();

    int index; //Creating Index
    //Checking arr and adding a count to the buckets to indicate how many values
    for(i=0; i<sizearr; i++){
        index = arr[i];
        bin[index] = bin[index]+1;
    }
    //Displaying sorted array by displaying the how many times index has been counted
    i = 0;
    index = 0;

    while(index < sizearr){
        //Check if count is greater than 0 then add the values on how many times it counted
        if(bin[index] > 0){
            for(int j = 0; j < bin[index]; j++){
                arr[i] = index;
                i++; //Move array
            }
        }
        index++; //Move Bin
    }
    time_req = clock() - time_req;
    cout << endl;
    cout << "The time it took = " << (float)time_req/CLOCKS_PER_SEC << endl;
    return 0;
}
