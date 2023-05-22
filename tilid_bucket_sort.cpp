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
#include <vector>
using namespace std;

void bucketSort(vector<int>& arr, int numBuckets) {
    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());

    double range = (maxValue - minValue + 1) / static_cast<double>(numBuckets);

    vector<vector<int>> buckets(numBuckets);

    for (int i = 0; i < arr.size(); ++i) {
        int bucketIndex = static_cast<int>((arr[i] - minValue) / range);
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < numBuckets; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < numBuckets; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    srand(time(0));
    clock_t time_req;
    int sizearr = 20;
    vector<int> arr;
    for(int i=0; i<sizearr; i++){
        arr.push_back (rand() % sizearr);
    }
    int numBuckets = 5;

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    time_req = clock();
    bucketSort(arr, numBuckets);
    time_req = clock() - time_req;
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "The time it took = " << (float)time_req/CLOCKS_PER_SEC << endl;
    return 0;
}


