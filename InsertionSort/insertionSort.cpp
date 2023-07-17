#include "InsertionSort.h"

void insertionSort(int* a,int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
void insertionSortCompare(int* a,int n,long long& compare)
{
    compare = 0;
    int i, key, j;
    for (i = 1; ++compare && i < n; i++) {
        key = a[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (++compare && j >= 0 && ++compare && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void insertionSortTime(int* a,int n,double& time)
{
    time = 0;
    clock_t start,end;

    start=clock();
    insertionSort(a,n);
    end=clock();

    // Measuring time
    time = (double)(end-start) / CLOCKS_PER_SEC * 1000;
}