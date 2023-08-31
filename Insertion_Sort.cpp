//Question: How can we sort a sub-array within a given range using insertion sort recursively?
//This algorithm utilzies insertion sort, which is a sorting method that sorts one element at a time by repeatedly inserting elements into the appropriate position.
//The base case is when there is only one element or less in the sub-array, and in that case, the function simply returns without doing anything.

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& A, int low, int high) {
    // Base case: if there is only one element or less, return
    if (low >= high) {
        return;
    }
    
    // Sorting the first n-1 elements recursively
    insertionSort(A, low, high-1);
    
    int last = A[high];
    int j = high - 1;
    while (j >= low && A[j] > last) {
        A[j+1] = A[j];
        j--;
    }
    A[j+1] = last;
}
