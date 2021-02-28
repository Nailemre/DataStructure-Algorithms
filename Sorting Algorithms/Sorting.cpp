// NAÝL EMRE KAYAPINAR
#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#include<iostream>
using namespace std;
/****************************************************
 * Uses bubble sort to sort A[0..N-1]
 ****************************************************/
void BubbleSort(int A[], int N) {
    int tmp;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }
} //end-BubbleSort

/****************************************************
 * Uses selection sort to sort A[0..N-1]
 ****************************************************/
void SelectionSort(int A[], int N) {
    int tmp;
    int min;
    for (int i = 0; i < N - 1; i++)
    {
        min = i;
        for (int j = i; j < N; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        tmp = A[i];
        A[i] = A[min];
        A[min] = tmp;
    }
} //end-SelectionSort

/****************************************************
 * Uses insertion sort to sort A[0..N-1]
 ****************************************************/
void InsertionSort(int A[], int N) {
    int tmp, i, j;
    for (i = 0; i < N; i++)
    {
        tmp = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > tmp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp;
    }
} //end-InsertionSort

/****************************************************
 * Uses mergesort to sort A[0..N-1]
 ****************************************************/
void merge(int* A, int low, int high, int mid)
{
    int i, j, k, c[32768];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j]) {
            c[k] = A[i];
            k++;
            i++;
        }
        else {
            c[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = A[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        A[i] = c[i];

    }
}
void merge_sort(int* arr, int low, int high)
{
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}
void MergeSort(int A[], int N) {
    merge_sort(A, 0, N - 1);

}//end-MergeSort



/****************************************************
 * Uses quicksort sort to sort A[0..N-1]
 ****************************************************/
int partition(int A[], int low, int high)
{
    int pivot = A[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;
    return (i + 1);
}
void quicksort(int A[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(A, low, high);

        quicksort(A, low, pi - 1);
        quicksort(A, pi + 1, high);
    }
}
void QuickSort(int A[], int N) {
    quicksort(A, 0, N - 1);
} //end-QuickSort

/****************************************************
 * Uses heapsort to sort A[0..N]
 * NOTICE: The first element is in A[0] not in A[1]
 ****************************************************/
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void HeapSort(int A[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(A, N, i);
    for (int i = N - 1; i >= 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
} //end-HeapSort

/****************************************************
 * Uses radixsort to sort A[0..N]
 ****************************************************/
int getMax(int A[], int N)
{
    int mx = A[0];
    for (int i = 1; i < N; i++)
        if (A[i] > mx)
            mx = A[i];
    return mx;
}
void countSort(int A[], int N, int exp)
{
    int output[32768];
    int i, count[10] = { 0 };
    for (i = 0; i < N; i++)
        count[(A[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = N - 1; i >= 0; i--)
    {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }
    for (i = 0; i < N; i++)
        A[i] = output[i];
}

void RadixSort(int A[], int N) {
    int m = getMax(A, N);
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(A, N, exp);
} //end-RadixSort

/****************************************************
 * Uses countingsort to sort A[0..N]
 ****************************************************/
void CountingSort(int A[], int N) {  
    int output[32768];
    int count[32768];
    int max = A[0];   
    for (int i = 1; i < N; i++) {
        if (A[i] > max)
            max = A[i];
    }    
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        count[A[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    } 
    for (int i = N - 1; i >= 0; i--) {
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }   
    for (int i = 0; i < N; i++) {
        A[i] = output[i];
    }
} //end-CountingSort