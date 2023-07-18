// Reference: https://www.thegioididong.com/game-app/quick-sort-la-gi-thuat-toan-sap-xep-nhanh-quick-sort-trong-c-1336679
#ifndef QUICKSORT_H
#define QUICKSORT_H


#pragma once
#include <iostream>
#include "time.h"
using namespace std;


void quickSort(int a[], int low, int high);
void quickSortCompare(int a[], int n, long long &comparison);
void quickSortTime(int a[], int n, double &time);


#endif