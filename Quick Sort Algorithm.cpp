//Question: How can we sort an array using the quicksort algorithm while efficiently handling situations where there are duplicate elements in the array? 
//The function uses the Lomuto partition scheme and maintains three indices lt, i, and gt to keep track of the boundaries of the three partitions.

#include <iostream>
#include <algorithm>

void quickSort3(int A[], int l, int r) {
    if (l >= r) {
        return;
    }
    int lt = l, gt = r, i = l + 1;
    int pivot = A[l];
    
    while (i <= gt) {
        //If the current element A[i] is less than the pivot, swap it with the element at index lt and increments both i and lt
        if (A[i] < pivot) {
            swap(A[i++], A[lt++]);
        }
        //If A[i] is greater than the pivot, swap it with the element at index gt and decrements gt.
        else if (A[i] > pivot) {
            swap(A[i], A[gt--]);
        }
        else {
            i++;
        }
    }
    
    quickSort3(A, l, lt - 1);
    quickSort3(A, gt + 1, r);
}
