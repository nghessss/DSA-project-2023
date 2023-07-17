
#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>
#include<time.h>
#include"Header/bubbleSort.h"
#include"Header/countingSort.h"
#include"Header/flashSort.h"
#include"Header/heapSort.h"
#include"Header/insertionSort.h"
#include"Header/mergeSort.h"
#include"Header/quickSort.h"
#include"Header/radixSort.h"
#include"Header/selectionSort.h"
#include"Header/shakeSort.h"
#include"Header/shellSort.h"

using namespace std;


//func in DataGenarator
template <class T>
void HoanVi(T &a, T &b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);


//func in command.cpp
void Command_1(char *argv[]);
void Command_2(char *argv[]);
void Command_3(char *argv[]);
void Command_4(char *argv[]);
void Command_5(char *argv[]);

#endif