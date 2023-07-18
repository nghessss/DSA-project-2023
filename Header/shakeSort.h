// Reference: https://daynhauhoc.com/t/cau-truc-du-lieu-va-giai-thuat-giai-thuat-sap-xep-rung-lac-shaker-sort/126359
#ifndef SHAKESORT_H
#define SHAKESORT_H


#pragma once
#include <iostream>
#include "time.h"
#include <string.h>
using namespace std;

void shakerSort(int a[], int n);
void shakerSortCompare(int a[], int n, long long &comparison);
void shakerSortTime(int a[], int n, double &time);


#endif