#ifndef HEAPSORT_H
#define HEAPSORT_H

// Referece: https://www.geeksforgeeks.org/heap-sort/

#include <time.h>
#include <iostream>

void heapSort(int* a,int n);
void heapSortCompare(int* a,int n,long long& compare);
void heapSortTime(int* a,int n,double& time);

#endif