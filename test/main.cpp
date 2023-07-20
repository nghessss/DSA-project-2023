#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;
const int dataSize[] = {10000, 30000, 50000, 100000, 300000, 500000};
const string dataType[] = {"random", "nsorted", "sorted", "rev"};
const int numBoard = 4;
const int numSort = 11;
const int numDataSize = 6;
pair<double, long long> a[numBoard][numDataSize][numSort];
void inputInto1D(pair<double, long long> a[], string fileName)
{
    ifstream is(fileName);
    if (!is)
    {
        cout << fileName << " doesnt exist" << endl;
        return;
    }
    for (int i = 0; i < numSort; i++)
    {
        string line, timeString, compString;
        getline(is, line);
        stringstream s(line);
        getline(s, timeString, ',');
        getline(s, compString, ',');
        double time = stod(timeString);
        long long comp = stoll(compString);
        a[i] = pair<double, long long>(time, comp);
    }
    is.close();
}
void inputInto3D(pair<double, long long> a[][numDataSize][numSort])
{
    for (int i = 0; i < numBoard; i++)
        for (int j = 0; j < numDataSize; j++)
        {
            string fileName = dataType[i] + "_" + to_string(dataSize[j]) + ".csv";
            inputInto1D(a[i][j], fileName);
        }
}
void print1D(pair<double, long long> a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i].first << ',' << a[i].second << endl;
}
int main()
{
    inputInto3D(a);
    print1D(a[3][5], numSort);
}