#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
const int dataSize[] = {10000, 30000, 50000, 100000, 300000, 500000};
const string dataType[] = {"random", "nsorted", "sorted", "rev"};
const int numBoard = 4;
const int numSort = 11;
const int numDataSize = 6;
void quanInput(pair<double, long long> a[][numDataSize][numSort])
{
    ifstream is("quan.csv");
    string line;
    getline(is, line);

    int i = 0, j = 0, k = 0;
    for (int j = 0; j < numDataSize; j++)
        for (int i = 0; i < numBoard; i++)
        {
            getline(is, line);
            stringstream s(line);
            string buf;
            getline(s, buf, ',');
            getline(s, buf, ',');
            for (int k = 0; k < numSort; k++)
            {
                string line, timeString, compString;
                getline(is, line);
                stringstream s(line);
                getline(s, timeString, ',');
                getline(s, compString, ',');
                double time = stod(timeString);
                long long comp = stoll(compString);
                a[i%4][j/4][k] = pair<double, long long>(time, comp);
            }
        }

    is.close();
}