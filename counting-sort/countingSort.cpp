#include "countingSort.h"

void countingSort(int a[], int n)
{
    int maxNum = 0;
    for (int i = 0; i < n; i++)
        if (maxNum < a[i])
            maxNum = a[i];

    int *count = new int[maxNum + 1];
    for (int i = 0; i < maxNum; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[a[i]]++;

    int i = 0;
    for (int num = 0; num <= maxNum; num++)
        while (count[num] > 0)
        {
            a[i++] = num;
            count[num]--;
        }
    delete count;
}
void countingSortCompare(int a[], int n, long long &comparison)
{
    comparison = 0;
    int maxNum = 0;
    for (int i = 0; ++comparison && i < n; i++)
        if (++comparison && maxNum < a[i])
            maxNum = a[i];

    int *count = new int[maxNum + 1];
    for (int i = 0; ++comparison && i < maxNum; i++)
        count[i] = 0;
    for (int i = 0; ++comparison && i < n; i++)
        count[a[i]]++;

    int i = 0;
    for (int num = 0; ++comparison && num <= maxNum; num++)
        while (++comparison && count[num] > 0)
        {
            a[i++] = num;
            count[num]--;
        }
    delete count;
}
void countingSortTime(int a[], int n, double &time)
{
    clock_t start, end;
    start = clock();
    countingSort(a, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}
