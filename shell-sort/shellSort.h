// Reference: https://www.geeksforgeeks.org/shellsort/
#ifndef SHELLSORT_H
#define SHELLSORT_H
#pragma once
#include <iostream>
#include "time.h"
#include <string.h>
using namespace std;
void shellSort(int a[], int n);
void shellSortCompare(int a[], int n, long long &comparison);
void shellSortTime(int a[], int n, double &time);
#endif//