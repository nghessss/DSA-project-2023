
#include "Header/flashSort.h"
#include"main.h"

// Flash Sort algorithm implementation
void flashSort(int a[], int n)
{
    int minVal = a[0], maxIndex = 0;
    int m = int(0.45 * n); // number of buckets
    int *l = new int[m]; // bucket array

    // Initialize bucket variable
    for (int i = 0; i < m; i++) {
        l[i] = 0;
    }
    
    // Find max index and min value
    for (int i = 1; i < n; i++) {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }
    
    if (a[maxIndex] == minVal)
        return;
    
    double c1 = (double)(m - 1) / (a[maxIndex] - minVal);
    
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    
    // Calculate last index of each bucket
    for (int i = 1; i < m; i++) {
        l[i] += l[i - 1];
    }
    
    HoanVi(a[maxIndex], a[0]);
    
    int nMove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;

    while (nMove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1*(a[j] - minVal));
        }
        flash = a[j];
        if (k < 0) break;
        while (j != l[k])
        {
            k = int(c1*(flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nMove;
        }
    }
    delete[] l;
    // Sort each bucket
    insertionSort(a, n);
}

// Calculate comparison
void flashSortCompare(int a[], int n, long long &comparison)
{
    int minVal = a[0], maxIndex = 0;
    int m = int(0.45 * n); // number of buckets
    int *l = new int[m]; // bucket array
    comparison = 0;

    // Initialize bucket variable
    for (int i = 0; i < m; i++) {
        ++comparison;
        l[i] = 0;
    }
    
    // Find max index and min value
    for (int i = 1; i < n; i++) {
        comparison += 3; // i compare to n and two 'if' lines
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }
    
    ++comparison;
    if (a[maxIndex] == minVal)
        return;
    
    double c1 = (double)(m - 1) / (a[maxIndex] - minVal);
    
    for (int i = 0; i < n; i++)
    {
        ++comparison;
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    
    // Calculate last index of each bucket
    for (int i = 1; i < m; i++) {
        ++comparison;
        l[i] += l[i - 1];
    }
    
    HoanVi(a[maxIndex], a[0]);
    
    int nMove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;

    while (++comparison && nMove < n - 1)
    {
        while (++comparison && j > l[k] - 1)
        {
            j++;
            k = int(c1*(a[j] - minVal));
        }
        flash = a[j];
        if (k < 0) break;
        while (++comparison && j != l[k])
        {
            k = int(c1*(flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nMove;
        }
    }
    
    delete[] l;
    // Sort each bucket
    insertionSortCompare(a, n, comparison);
}

// Calculate time of Flash Sort algorithm
void flashSortTime(int a[], int n, double &time)
{
    int minVal = a[0], maxIndex = 0;
    int m = int(0.45 * n); // number of buckets
    int *l = new int[m]; // bucket array
    clock_t start, end;
    start = clock(); // start time

    flashSort(a, n);

    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    // Sort each bucket
    double timeInsert;
    insertionSortTime(a, n, timeInsert);
    time += timeInsert;
}