#ifndef CS124_PROJECT4_SELECTIONSORTTWOSORT_H
#define CS124_PROJECT4_SELECTIONSORTTWOSORT_H

#include "printVec.h"

template<typename Comparable>
void selectionSortTwoSort(vector<Comparable> vec) {
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


}


#endif //CS124_PROJECT4_SELECTIONSORTTWOSORT_H
