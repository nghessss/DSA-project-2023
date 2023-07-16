#include "mergeSort.h"

void merge(int *a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create two temporary arrays
    int L[n1], R[n2];

    // Copy data into these two arrays
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    // Merge the two arrays back into the main array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    // Copy the remaining elements
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(int *a, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort the left and right halves
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        // Merge the two sorted halves
        merge(a, left, mid, right);
    }
}

void mergeSortTime(int *a, int left, int right, double &time)
{
    time = 0;
    clock_t start, end;

    start = clock();
    mergeSort(a, left, right);
    end = clock();

    // Measuring time
    time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
}

void mergeCompare(int *a, int left, int mid, int right, int &compare)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create two temporary arrays
    int L[n1], R[n2];

    // Copy data into these two arrays
    for (int i = 0; ++compare && i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; ++compare && j < n2; j++)
        R[j] = a[mid + 1 + j];

    // Merge the two arrays back into the main array
    int i = 0, j = 0, k = left;
    while (++compare && i < n1 && ++compare && j < n2)
    {
        if (++compare && L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    // Copy the remaining elements
    while (++compare && i < n1)
        a[k++] = L[i++];
    while (++compare && j < n2)
        a[k++] = R[j++];
}

void mergeSortCompare1(int *a, int left, int right, int &compare)
{
    if (++compare && left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort the left and right halves
        mergeSortCompare1(a, left, mid,compare);
        mergeSortCompare1(a, mid + 1, right,compare);

        // Merge the two sorted halves
        mergeCompare(a, left, mid, right,compare);
    }
}

void mergeSortCompare(int *a, int left, int right, int &compare)
{
    compare = 0;
    mergeSortCompare1(a,left,right,compare);
}