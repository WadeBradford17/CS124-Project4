#ifndef SORTING_INSERTIONSORTSECONDFIELD_H
#define SORTING_INSERTIONSORTSECONDFIELD_H

#include "printVec.h"


void insertionSortSecondField(vector<Streamer> vec) {
    int numReads = 0;
    int numWrites = 0;
    int unsortedStartIndex, insertIndex;
   Streamer toBeInserted;
    for (unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        toBeInserted = vec[unsortedStartIndex];
        numWrites += 1;
        numReads += 1;
        // Loop to shift over the larger elements
        insertIndex = unsortedStartIndex - 1;
        while (insertIndex >= 0 && vec[insertIndex].getPeakViewers() > toBeInserted.getPeakViewers()) {
            vec[insertIndex + 1] = vec[insertIndex];
            numReads += 3;
            numWrites += 1;
            --insertIndex;
        }
        // Put toBeInserted back into vec
        vec[insertIndex + 1] = toBeInserted;
        numWrites += 1;
        numReads += 1;
       // printVec(vec);

    }
    cout << "Number of writes: " << numWrites << endl;
    cout << "Number of reads: " << numReads << endl;
}

#endif