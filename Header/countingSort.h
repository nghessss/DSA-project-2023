
#ifndef COUNINGSORT_H
#define COUNINGSORT_H


#pragma once
#include <iostream>
#include "time.h"
using namespace std;


void countingSort(int a[], int n);
void countingSortCompare(int a[], int n, long long &comparison);
void countingSortTime(int a[], int n, double &time);


#endif