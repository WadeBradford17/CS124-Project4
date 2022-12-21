#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "printVec.h"

template<typename Comparable>
void quickSortStableRec(vector<Comparable> &vec, int& numWrites, int& numReads) {
    // Recursive base case
    if (vec.size() <= 1) {
        return;
    }

    // Choose a partition element
    Comparable partition = vec[0];
    vector<Comparable> smaller, equal, larger;

    numReads += 1;
    numWrites += 4;
    // Loop through vec and populate smaller, equal, larger
    int i;
    for (i = 0; i < vec.size(); ++i) {
        if (vec[i] < partition) {
            smaller.push_back(vec[i]);
        } else if (vec[i] > partition) {
            larger.push_back(vec[i]);
        } else {
            equal.push_back(vec[i]);
        }
        numReads += 2;
        numWrites += 1;
    }

    // Recursive calls
    quickSortStableRec(smaller,numWrites, numReads);
    quickSortStableRec(larger, numWrites, numReads);

    // Copy elements from smaller, equal, and larger back into vec
    for (i = 0; i < vec.size(); ++i) {
        if (i < smaller.size()) {
            vec[i] = smaller[i];
            numWrites += 1;
            numReads += 1;
        } else if (i < smaller.size() + equal.size()) {
            vec[i] = equal[i - smaller.size()];
            numWrites += 1;
            numReads += 1;
        } else {
            vec[i] = larger[i - smaller.size() - equal.size()];
            numWrites += 1;
            numReads += 1;
        }
    }
   // printVec(vec);
}

template<typename Comparable>
void quickSortStable(vector<Comparable> vec) {
    int a = 0;
    int b = 0;

    quickSortStableRec(vec, a, b);

    cout << "Number of writes: " << a << endl;
    cout << "Number of reads: " << b << endl;

}

#endif