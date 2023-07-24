#include "Header/countingSort.h"

void countingSort(int a[], int n)
{
    int *output = new int[n];
    int Max = a[0];
    int Min = a[0];

    int i;
    for (i = 1; i < n; i++)
    {
        if (a[i] > Max)
            Max = a[i];
        else if (a[i] < Min)
            Min = a[i];
    }

    int k = Max - Min + 1;

    int *count_array = new int[k];
    for (i = 0; i < k; i++)
        count_array[i] = 0;

    for (i = 0; i < n; i++)
        count_array[a[i] - Min]++;

    for (i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];

    for (i = 0; i < n; i++)
    {
        output[count_array[a[i] - Min] - 1] = a[i];
        count_array[a[i] - Min]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
    delete count_array;
    delete output;
}
void countingSortCompare(int a[], int n, long long &comparison)
{
    comparison = 0;
    int *output = new int[n];
    int Max = a[0];
    int Min = a[0];

    int i;
    for (i = 1; i < n; i++)
    {
        if (a[i] > Max)
            Max = a[i];
        else if (a[i] < Min)
            Min = a[i];
    }

    int k = Max - Min + 1;

    int *count_array = new int[k];
    for (i = 0; i < k; i++)
        count_array[i] = 0;

    for (i = 0; i < n; i++)
        count_array[a[i] - Min]++;

    for (i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];

    for (i = 0; i < n; i++)
    {
        output[count_array[a[i] - Min] - 1] = a[i];
        count_array[a[i] - Min]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
    delete count_array;
    delete output;
}
void countingSortTime(int a[], int n, double &time)
{
    clock_t start, end;
    start = clock();
    countingSort(a, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
}
