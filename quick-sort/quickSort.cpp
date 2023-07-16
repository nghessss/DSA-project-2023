#include "quickSort.h"
int partition(int a[], int first, int last)
{
    int pivot = a[first];
    int l, r;
    l = first;
    for (r = first + 1; r <= last; r++)
    {
        if (a[r] < pivot)
        {
            swap(a[r], a[l + 1]);
            ++l;
        }
    }
    swap(a[first], a[l]);
    return l;
}
void quickSort(int a[], int first, int last)
{
    if (first < last)
    {
        int pivotIndex = partition(a, first, last);

        quickSort(a, first, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, last);
    }
}

int partitionCompare(int a[], int first, int last, int &comparison)
{
    int pivot = a[first];
    int l, r;
    l = first;
    for (r = first + 1; ++comparison && r <= last; r++)
    {
        if (++comparison && a[r] < pivot)
        {
            swap(a[r], a[l + 1]);
            ++l;
        }
    }
    swap(a[first], a[l]);
    return l;
}
void quickSortCompare(int a[], int first, int last, int &comparison)
{
    if (++comparison && first < last)
    {
        int pivotIndex = partitionCompare(a, first, last, comparison);

        quickSort(a, first, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, last);
    }
}
void quickSortTime(int a[], int first, int last, double &time)
{
    clock_t start, end;
    start = clock();
    quickSort(a, first, last);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
