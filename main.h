#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>
#include<time.h>
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

#endif