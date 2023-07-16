#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

// Reference: https://www.geeksforgeeks.org/insertion-sort/

#include <time.h>
#include <iostream>

void insertionSort(int* a,int n);
void insertionSortCompare(int* a,int n,int& compare);
void insertionSortTime(int* a,int n,double& time);

#endif