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

#include <iostream>
#include <array>

using namespace std;

void countingSort(int arr[], int n, int exp) {
    const int radix = 10; // Base 10 for decimal numbers

    array<int, 10> count = {0};
    int output[n];

    for (int i = 0; i < n; ++i) {
        int digit = (arr[i] / exp) % radix;
        count[digit]++;
    }

    for (int i = 1; i < radix; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % radix;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int maxNum = *max_element(arr, arr + n);

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    srand(time(0));
    clock_t time_req;
    int sizearr = 20;
    int arr[sizearr];
    for(int i=0; i<sizearr; i++){
        arr[i] = rand() % sizearr;
    }
    cout << "Original array: ";
    for (int i = 0; i < sizearr; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    radixSort(arr, sizearr);

    cout << "Sorted array: ";
    for (int i = 0; i < sizearr; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
