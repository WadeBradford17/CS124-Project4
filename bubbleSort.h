#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "printVec.h"

template<typename Comparable>
void bubbleSort(vector<Comparable> vec) {
    int numPasses = 0, i;
    int numReads = 0;
    int numWrites= 0;
    Comparable temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i+1]) {

                temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;

                numReads += 3;
                numWrites += 3;
                // Update haveSwapped
                haveSwapped = true;
            }
            numReads += 2;
        }
        // Update numPasses
        ++numPasses;

    }

    cout << "Number of writes: " << numWrites << endl;
    cout << "Number of reads: " << numReads << endl;
}

#endif