/*
 * Wade Bradford
 * CS 124
 * Project 4
 */

using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Streamer.h"
#include "bubbleSort.h"
#include "heapSort.h"
#include "insertionSortSecondField.h"
#include "printVec.h"
#include "selectionSort.h"
#include "quickSort.h"
#include "selectionSortTwoSort.h"

int main() {

    vector<Streamer> streamersBubble;
    vector<Streamer> streamersSelection;
    vector<Streamer> streamersQuick;
    vector<Streamer> streamersHeap;
    vector<Streamer> streamersTwo;
    string fn = "../twitchdata-update.csv";
    cout << endl;

    readDataFromFile(fn, streamersSelection);
    readDataFromFile(fn, streamersQuick);
    readDataFromFile(fn, streamersHeap);
    readDataFromFile(fn, streamersTwo);

    // reads file and stores into vector
    if (readDataFromFile(fn, streamersBubble)) {
        cout << streamersBubble.size() << " steamers read from file" << std::endl;
        string firstName = streamersBubble.front().getStreamerName();
        cout << "The first streamer read was " << firstName << endl;
        string lastName = streamersBubble.back().getStreamerName();
        cout << "The last streamer read was " << lastName << endl;
    } else {
        cout << "Something went wrong." << endl;
    }

    cout << endl;


    // BUBBLE SORT
    for (int i = 1000; i >= 100; i -= 100) {
        cout << "Bubble Sort (" << i << "):" << endl;
        bubbleSort(streamersBubble);
        streamersBubble.resize(i-100);
        cout << endl;
    }

    cout << "-------------------------------------------" << endl;
    cout << endl;

    // SELECTION SORT
    for (int i = 1000; i >= 100; i -= 100) {
        cout << "Selection Sort (" << i << "):" << endl;
        selectionSort(streamersSelection);
        streamersSelection.resize(i-100);
        cout << endl;
    }

    cout << "-------------------------------------------" << endl;
    cout << endl;

    // QUICK SORT
    for (int i = 1000; i >= 100; i -= 100) {
        cout << "Quick Sort (" << i << "):" << endl;
        quickSortStable(streamersQuick);
        streamersQuick.resize(i-100);
        cout << endl;
    }

    cout << "-------------------------------------------" << endl;
    cout << endl;

    // HEAP SORT
    for (int i = 1000; i >= 100; i -= 100) {
        cout << "HEAP Sort (" << i << "):" << endl;
        heapSort(streamersHeap);
        streamersHeap.resize(i-100);
        cout << endl;
    }

    cout << "-------------------------------------------" << endl;
    cout << endl;

    // TWO SORT
    for (int i = 1000; i >= 100; i -= 100) {
        cout << "TWO Sort (" << i << "):" << endl;
        selectionSortTwoSort(streamersTwo);
        insertionSortSecondField(streamersTwo);
        streamersTwo.resize(i-100);
        cout << endl;
    }

}