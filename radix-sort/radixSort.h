// Reference: https://www.geeksforgeeks.org/radix-sort/
#ifndef RADIXSORT_H
#define RADIXSORT_H
#pragma once
#include <iostream>
#include "time.h"
#include <string.h>
using namespace std;

void countingSort(int a[], int n, int exp);

void radixSort(int a[], int n);

void countingSortCompare(int a[], int n, int exp, int &comparison);

void radixSortCompare(int a[], int n, int &comparison);

void radixSortTime(int a[], int n, double &time);

#endif