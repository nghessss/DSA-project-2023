#include "bubbleSort.h"

void bubbleSort(int *a, int n)
{
    // loop to access each array element
    for (int step = 0; step < n; ++step)
    {

        // loop to compare array elements
        for (int i = 0; i < n - step; ++i)
        {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (a[i] > a[i + 1])
            {

                // swapping elements if elements
                // are not in the intended order
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

void bubbleSortCompare(int *a, int n, long long &compare)
{
    compare = 0;
    // loop to access each array element
    for (int step = 0; ++compare && step < n; ++step)
    {

        // loop to compare array elements
        for (int i = 0; ++compare && i < n - step; ++i)
        {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (++compare && a[i] > a[i + 1])
            {

                // swapping elements if elements
                // are not in the intended order
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

void bubbleSortTime(int *a, int n, double &time)
{
    time = 0;
    clock_t start, end;

    start = clock();
    bubbleSort(a, n);
    end = clock();

    // Measuring time
    time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
}