#ifndef MERGESORT_H
#define MERGESORT_H

// Reference: https://www.geeksforgeeks.org/merge-sort/

#include <time.h>
#include <iostream>

void mergeSort(int *a, int left, int right);
void mergeSortTime(int *a, int n, double &time);
void mergeSortCompare(int *a, int n, long long &compare);

#endif