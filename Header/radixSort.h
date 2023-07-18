// Reference: https://www.geeksforgeeks.org/radix-sort/
#ifndef RADIXSORT_H
#define RADIXSORT_H


#pragma once
#include <iostream>
#include "time.h"
#include <string.h>
using namespace std;


void radixSort(int a[], int n);
void radixSortCompare(int a[], int n, long long &comparison);
void radixSortTime(int a[], int n, double &time);

#endif