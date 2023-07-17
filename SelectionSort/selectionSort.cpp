#include "selectionSort.h"

void selectionSort(int *a, int n)
{
    // One by one move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIdx])
                minIdx = j;
        }

        // Swap the minimum element with the first element
        if (minIdx != i)
            std::swap(a[minIdx], a[i]);
    }
}

void selectionSortCompare(int *a, int n, long long &compare)
{
    compare = 0;

    for (int i = 0; ++compare && i < n - 1; i++)
    {
        // Find the minimum element
        int minIdx = i;
        for (int j = i + 1; ++compare && j < n; j++)
        {
            if (++compare && a[j] < a[minIdx])
            {
                minIdx = j;
            }
        }

        // Swap the minimum element with the first element
        if (++compare && minIdx != i)
            std::swap(a[minIdx], a[i]);
    }
}

void selectionSortTime(int *a, int n, double &time)
{
    time = 0;

    clock_t start, end;
    start = clock();
    selectionSort(a, n);
    end = clock();

    // Measuring time
    time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
}