#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

// Reference: https://www.geeksforgeeks.org/selection-sort/

#include <time.h>
#include <iostream>

void selectionSort(int* a,int n);
void selectionSortCompare(int* a,int n,long long& compare);
void selectionSortTime(int* a,int n,double& time);

#endif