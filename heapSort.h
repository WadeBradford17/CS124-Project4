#ifndef SORTING_HEAPSORT_H
#define SORTING_HEAPSORT_H

#include "printVec.h"
#include <vector>
using std::vector;

// Helper function for heapSort
inline int leftChild(int i) {
    return 2 * i + 1;
}

// Helper function for heapSort
// i is the index of the value being percolated down
// n is the number of items in the heap
template <typename Comparable>
void percolateDown(vector<Comparable> &items, int& i, unsigned long& n, int& child, Comparable& tmp, int& numReads, int& numWrites) {
    for(tmp = items[i]; leftChild(i) < n; i = child) {
        child = leftChild(i);
        numWrites += 1;
        numReads += 1;
        // choose the child with the larger value
        if (child != n - 1 && items[child] < items[child + 1]) {
            numReads += 2;
            ++child;
        }
        // if the parent is less than the child, swap them
        if (tmp < items[child]) {
            items[i] = items[child];
            numReads += 3;
            numWrites += 1;
        } else {
            // parent is >= both children. nothing more to do.
            break;
        }
    }
    items[i] = tmp;
    numReads += 1;
    numWrites += 1;
}

template <typename Comparable>
vector<Comparable> heapSort(vector<Comparable> items) {
    int numReads = 0;
   int numWrites = 0;
    int i, child;
    Comparable temp, tmp;
    unsigned long j, n;
    // build the heap (with max value at root)
    for (i = items.size() / 2 - 1; i >= 0; --i) {
        n = items.size();
        percolateDown(items, i, n, child, tmp, numReads, numWrites);
    }
  //  printVec(items);
    // keep deleting the max
    for (j = items.size() - 1; j > 0; --j) {
        // swap the maximum out
        temp = items[0];
        items[0] = items[j];
        items[j] = temp;
        numReads += 3;
        numWrites += 3;

        // make it into a heap again
        i = 0;
        percolateDown(items, i, j, child, tmp, numReads, numWrites);

       // printVec(items);
    }
    cout << "Number of writes: " << numWrites << endl;
    cout << "Number of reads: " << numReads << endl;
    return items;

}

#endif