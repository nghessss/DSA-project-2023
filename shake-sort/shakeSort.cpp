#include "shakeSort.h"
void shakerSort(int a[], int n)
{
    int left, right, k, i;
    left = 0;
    right = n - 1;
    k = 0;
    while (left < right)
    {
        for (int i = left; i < right; i++)
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        right = k;

        for (int i = right; i > left; i--)
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        left = k;
    }
}
void shakerSortCompare(int a[], int n, int &comparison)
{
    comparison = 0;
    int left, right, k, i;
    left = 0;
    right = n - 1;
    k = 0;
    while (++comparison && left < right)
    {
        for (int i = left; ++comparison && i < right; i++)
            if (++comparison && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        right = k;

        for (int i = right; ++comparison && i > left; i--)
            if (++comparison && a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        left = k;
    }
}
void shakerSortCompare(int a[], int n, double &time)
{
    clock_t start, end;
    start = clock();
    shakerSort(a, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}