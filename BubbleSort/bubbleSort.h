#ifndef BUBBLESORT_H
#define BUBBLESORT_H

// Reference: https://www.programiz.com/dsa/bubble-sort

#include <time.h>
#include <iostream>

void bubbleSort(int* a,int n);
void bubbleSortCompare(int* a,int n,int& compare);
void bubbleSortTime(int* a,int n,double& time);

#endif