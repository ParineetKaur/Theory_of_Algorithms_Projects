//Question: Modify the standard merge sort algorithm to work with three-way splitting of the input array, where the array is divided into three roughly equal-sized subarrays instead of two. Implement the necessary functions to recursively sort these subarrays and then merge them back together.
//mergeSort3 function divides the array into three subarrays and recursively sorts them
//merge3 function performs the merging of the sorted subarrays using a three-way merging strategy

#include <iostream>

void merge3(int A[], int low, int mid1, int mid2, int high) {
    int n1 = mid1 - low;
    int n2 = mid2 - mid1;
    int n3 = high - mid2;
    
    int L[n1], M[n2], R[n3]; //Temporary Arrays facilitating the merging of three sorted subarrays into single sorted array
    
    for (int i = 0; i < n1; i++)
        L[i] = A[low + i];
    for (int i = 0; i < n2; i++)
        M[i] = A[mid1 + i];
    for (int i = 0; i < n3; i++)
        R[i] = A[mid2 + i];
    
    int i = 0, j = 0, k = 0, l = low;
    
    while (i < n1 && j < n2 && k < n3) {
        if (L[i] <= M[j] && L[i] <= R[k])
            A[l++] = L[i++];
        else if (M[j] <= L[i] && M[j] <= R[k])
            A[l++] = M[j++];
        else
            A[l++] = R[k++];
    }
    
    while (i < n1 && j < n2) {
        if (L[i] <= M[j])
            A[l++] = L[i++];
        else
            A[l++] = M[j++];
    }
    
    while (j < n2 && k < n3) {
        if (M[j] <= R[k])
            A[l++] = M[j++];
        else
            A[l++] = R[k++];
    }
    
    while (i < n1 && k < n3) {
        if (L[i] <= R[k])
            A[l++] = L[i++];
        else
            A[l++] = R[k++];
    }
    
    while (i < n1)
        A[l++] = L[i++];
    while (j < n2)
        A[l++] = M[j++];
    while (k < n3)
        A[l++] = R[k++];
}

void mergeSort3(int A[], int low, int high) {
    if (low < high) {
        // Calculate split points for the three subarrays
        int len = (high - low + 1) / 3;
        int mid1 = low + len;
        int mid2 = low + len * 2;

        // Recursively sort and merge the three subarrays
        mergeSort3(A, low, mid1 - 1);
        mergeSort3(A, mid1, mid2 - 1);
        mergeSort3(A, mid2, high);
        
        merge3(A, low, mid1, mid2, high);
    }
}
