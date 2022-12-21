#ifndef SORTING_SELECTIONSORT_H
#define SORTING_SELECTIONSORT_H

#include "printVec.h"

template<typename Comparable>
void selectionSort(vector<Comparable> vec) {
    int swapIndex, i, minIndex;
    int numWrites = 0;
    int numReads = 0;
    Comparable temp;
    for (swapIndex = 0; swapIndex < vec.size()-1; ++swapIndex) {
        // Loop through vector starting at swapIndex and keep track of min
        minIndex = swapIndex;
        for (i = swapIndex+1; i < vec.size(); ++i) {
            if (vec[i] < vec[minIndex]) {
                // We have a new minimum
                minIndex = i;
            }
            numReads += 2;
        }
        // Swap min value into swapIndex spot in vector
        temp = vec[swapIndex];
        vec[swapIndex] = vec[minIndex];
        vec[minIndex] = temp;
        numWrites += 3;
        numReads += 3;
    }
    // printVec(vec);
    //

    cout << "Number of writes: " << numWrites << endl;
    cout << "Number of reads: " << numReads << endl;

}

#endif