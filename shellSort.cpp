#include "Header/shellSort.h"

void shellSort(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}
void shellSortCompare(int a[], int n, long long &comparison)
{
    comparison = 0;
    for (int gap = n / 2; ++comparison && gap > 0; gap /= 2)
    {
        for (int i = gap; ++comparison && i < n; i++)
        {
            int temp = a[i];
            int j;
            for (j = i; ++comparison && j >= gap && ++comparison && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}
void shellSortTime(int a[], int n, double &time)
{
    clock_t start, end;
    start = clock();
    shellSort(a, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
}
