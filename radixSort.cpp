#include "Header/radixSort.h"

void countingSort(int a[], int n, int exp)
{
    int *output = new int[n];
    int *count = new int[10];
    for (int i = 0; i < 10; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
    delete output;
    delete count;
}

void radixSort(int a[], int n)
{
    int maxNum = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > maxNum)
            maxNum = a[i];

    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countingSort(a, n, exp);
}

void countingSortCompare(int a[], int n, int exp, long long &comparison)
{
    int *output = new int[n];
    int *count = new int[10];
    for (int i = 0; ++comparison && i < 10; i++)
        count[i] = 0;
    for (int i = 0; ++comparison && i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; ++comparison && i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; ++comparison && i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; ++comparison && i < n; i++)
        a[i] = output[i];
    delete output;
    delete count;
}

void radixSortCompare(int a[], int n, long long &comparison)
{
    comparison = 0;
    int maxNum = a[0];
    for (int i = 1; ++comparison && i < n; i++)
        if (++comparison && a[i] > maxNum)
            maxNum = a[i];

    for (int exp = 1; ++comparison && maxNum / exp > 0; exp *= 10)
        countingSort(a, n, exp);
}

void radixSortTime(int a[], int n, double &time)
{
    clock_t start, end;
    start = clock();
    radixSort(a, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
}
