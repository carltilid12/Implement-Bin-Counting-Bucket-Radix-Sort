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

#include <iomanip>
#include <iostream>
using namespace std;

#define NARRAY 100   // Array size
#define NBUCKET 10  // Number of buckets
#define INTERVAL (NARRAY/10)  // Each bucket capacity

struct Node {
    int data;
    struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);

// Sorting function
void BucketSort(int arr[]) {
    int i, j;
    struct Node **buckets;

    // Create buckets and allocate memory size
    buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

    // Initialize empty buckets
    for (i = 0; i < NBUCKET; ++i) {
        buckets[i] = NULL;
    }

    // Fill the buckets with respective elements
    for (i = 0; i < NARRAY; ++i) {
        struct Node *current;
        int pos = getBucketIndex(arr[i]);
        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = arr[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }
    // Sort the elements of each bucket
    for (i = 0; i < NBUCKET; ++i) {
        buckets[i] = InsertionSort(buckets[i]);
    }

    // Put sorted elements on arr
    for (j = 0, i = 0; i < NBUCKET; ++i) {
        struct Node *node;
        node = buckets[i];
        while (node) {
        arr[j++] = node->data;
        node = node->next;
        }
    }

    for (i = 0; i < NBUCKET; ++i) {
        struct Node *node;
        node = buckets[i];
        while (node) {
        struct Node *tmp;
        tmp = node;
        node = node->next;
        free(tmp);
        }
    }
    free(buckets);
    return;
}

// Function to sort the elements of each bucket
struct Node *InsertionSort(struct Node *list) {
    struct Node *k, *nodeList;
    if (list == 0 || list->next == 0) {
        return list;
    }

    nodeList = list;
    k = list->next;
    nodeList->next = 0;
    while (k != 0) {
        struct Node *ptr;
        if (nodeList->data > k->data) {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }

        for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
            if (ptr->next->data > k->data)
                break;
        }

        if (ptr->next != 0) {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        } 
        else {
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }
    return nodeList;
}

int getBucketIndex(int value) {
    return value / INTERVAL;
}

// Print buckets
void print(int ar[]) {
    int i;
    for (i = 0; i < NARRAY; ++i) {
        cout << setw(3) << ar[i];
    }
    cout << endl;
}

void printBuckets(struct Node *list) {
    struct Node *cur = list;
    while (cur) {
        cout << setw(3) << cur->data;
        cur = cur->next;
    }
}

// Driver code
int main(void) {
    srand(time(0));
    clock_t time_req;
    int array[NARRAY];
    for(int i=0; i<NARRAY; i++){
        array[i] = rand() % NARRAY;
    }

    //print(array);
    time_req = clock();
    BucketSort(array);
    time_req = clock() - time_req;
    cout << endl;
    cout << "The time it took = " << (float)time_req/CLOCKS_PER_SEC << endl;
    //print(array);
}
