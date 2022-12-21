#ifndef MERGESORT_H
#define MERGESORT_H

#include "printVec.h"

template<typename Comparable>
void mergeSortRec(vector<Comparable> &vec, int startIndex, int endIndex) {
    int numReads = 0;
    int numWrites = 0;

    // Recursive base case
    if (startIndex >= endIndex) {
        return;
    }

    // Recursive calls for the left and right halves
    int centerIndex = (startIndex + endIndex) / 2;
    mergeSortRec(vec, startIndex, centerIndex);
    mergeSortRec(vec, centerIndex + 1, endIndex);

    // Merge
    vector<Comparable> temp;
    int leftIndex = startIndex;
    int rightIndex = centerIndex + 1;
    // While leftIndex and rightIndex are in bounds of their half
    while (leftIndex <= centerIndex && rightIndex <= endIndex) {
        numReads += 3;
        numWrites += 1;
        if (vec[leftIndex] <= vec[rightIndex]) {
            temp.push_back(vec[leftIndex]);
            ++leftIndex;
        } else {
            temp.push_back(vec[rightIndex]);
            ++rightIndex;
        }
    }
    // Now one of the halves is empty and the other half has at least one element left to copy into temp
    while (leftIndex <= centerIndex) {
        temp.push_back(vec[leftIndex]);
        numReads += 1;
        numWrites += 1;
        ++leftIndex;
    }
    while (rightIndex <= endIndex) {
        temp.push_back(vec[rightIndex]);
        numReads += 1;
        numWrites += 1;
        ++rightIndex;
    }
    // Now everything between startIndex and endIndex is copied into temp
    // Copy everything from temp back into vec
    for (int i = 0; i < temp.size(); ++i) {
        vec[i + startIndex] = temp[i];
        numReads += 1;
        numWrites += 1;
    }

}


template<typename Comparable>
void mergeSort(vector<Comparable> vec) {
    int numReads = 0;
    int numWrites = 0;
    mergeSortRec(vec, 0, vec.size() - 1);
    cout << "Number of writes: " << numWrites << endl;
    cout << "Number of reads " << numReads << endl;
}

#endif