#ifndef FLASH_H
#define FLASH_H
#pragma once

#include <iostream>
#include "time.h"
using namespace std;

void flashSort(int a[], int n);
void flashSortCompare(int a[], int n, long long &comparison);
void flashSortTime(int a[], int n, double &time);
#endif