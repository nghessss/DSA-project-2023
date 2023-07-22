#include "main.h"

string Order[] = {"Randomize", "Nearly Sorted", "Sorted", "Reversed"};
string Algorithm[] = {"Selection Sort", "Insertion Sort", "Bubble Sort", "Shaker Sort", "Shell Sort", "Heap Sort", "Merge Sort", "Quick Sort", "Counting Sort", "Radix Sort", "Flash Sort"};

typedef void (*SortFunction)(int *, int, long long &);
typedef void (*SortTimeFunction)(int *, int, double &);

SortFunction sortingFunctions[] = {
    selectionSortCompare,
    insertionSortCompare,
    bubbleSortCompare,
    shakerSortCompare,
    shellSortCompare,
    heapSortCompare,
    mergeSortCompare,
    quickSortCompare,
    countingSortCompare,
    radixSortCompare,
    flashSortCompare};

SortTimeFunction sortingTimeFunctions[] = {
    selectionSortTime,
    insertionSortTime,
    bubbleSortTime,
    shakerSortTime,
    shellSortTime,
    heapSortTime,
    mergeSortTime,
    quickSortTime,
    countingSortTime,
    radixSortTime,
    flashSortTime};

// this func will take the order of data (0 : randomize; 1 : sorted; 2 : reversed; 3 :Nearly Sorted)
int GetDataType(char *Order)
{
    if (!strcmp(Order, "-rand"))
        return 0;
    else if (!strcmp(Order, "-nsorted"))
        return 1;
    else if (!strcmp(Order, "-sorted"))
        return 2;
    else if (!strcmp(Order, "-rev"))
        return 3;

    cout << "wrong dataType format, please check\n";
    return -1;
}

// Creat a outputType(0,1,2)
int GetOutputType(char *str)
{
    if (!strcmp(str, "-time"))
        return 0;
    else if (!strcmp(str, "-comp"))
        return 1;
    else if (!strcmp(str, "-both"))
        return 2;
    else
    {
        cout << "wrong Output parameter format, please check again\n";
        return -1;
    }
}

int GetAlgorithmType(char *Algorithm)
{
    if (!strcmp(Algorithm, "selection-sort"))
        return 0;
    else if (!strcmp(Algorithm, "insertion-sort"))
        return 1;
    else if (!strcmp(Algorithm, "bubble-sort"))
        return 2;
    else if (!strcmp(Algorithm, "shaker-sort"))
        return 3;
    else if (!strcmp(Algorithm, "shell-sort"))
        return 4;
    else if (!strcmp(Algorithm, "heap-sort"))
        return 5;
    else if (!strcmp(Algorithm, "merge-sort"))
        return 6;
    else if (!strcmp(Algorithm, "quick-sort"))
        return 7;
    else if (!strcmp(Algorithm, "counting-sort"))
        return 8;
    else if (!strcmp(Algorithm, "radix-sort"))
        return 9;
    else if (!strcmp(Algorithm, "flash-sort"))
        return 10;

    cout << "Wrong Algorithm, please check your command line\n";
    return -1;
}

int *CopyArr(int *a, int n)
{
    int *b = new int[n];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    return b;
}
void SortArray(int *a, int n, SortFunction sortingFunction, SortTimeFunction timeFunction, long long &CountCompare, double &Time, int OutputType)
{
    Time = 0;
    CountCompare = 0;
    // only time
    if (OutputType == 0)
        timeFunction(a, n, Time);
    else if (OutputType == 1)
        sortingFunction(a, n, CountCompare);
    else
    {
        int *b = CopyArr(a, n);
        timeFunction(a, n, Time);
        sortingFunction(b, n, CountCompare);
        delete[] b;
    }
}

void PrintResult(double Time, long long CountCompare, int OutputType)
{
    if (OutputType == 0)
        cout << "Running Time : " << Time << " ms " << endl;
    // compare only
    else if (OutputType == 1)
        cout << "Comparision Time : " << CountCompare << " comparisons " << endl;
    // both
    else
    {
        cout << "Running Time : " << Time << endl;
        cout << "Comparision : " << CountCompare << endl;
    }
}

void ReadFile(int *&a, int &n, const char *filename)
{
    ifstream is;
    is.open(filename);
    if (!is.is_open())
    {
        cout << "unable to open " << filename << ", please check\n";
        return;
    }
    is >> n;
    is.ignore();
    
    a = new int[n];
    int idx = 0;
    while (!is.eof())
    {
        is >> a[idx++];
    }
    is.close();
}

void WriteFile(const char *filename, int *a, int n)
{
    ofstream os;
    os.open(filename);
    os << n << endl;

    for (int i = 0; i < n; i++)
        os << a[i] << " ";

    os.close();
}

void Command_1(char *argv[])
{
    int *a;
    int OutputType;
    int AlgorithmType;
    int size;
    double Time = 0;
    long long CountCompare = 0;
    bool Success = true;

    OutputType = GetOutputType(argv[4]);
    if (OutputType == -1)
        return;

    AlgorithmType = GetAlgorithmType(argv[2]);
    if (AlgorithmType == -1)
        return;

    // Read Array From file
    ReadFile(a, size, argv[3]);

    // Sort Array
    SortArray(a, size, sortingFunctions[AlgorithmType], sortingTimeFunctions[AlgorithmType], CountCompare, Time, OutputType);
    if (!Success)
        return;

    // Result
    cout << "Algorithm: " << Algorithm[AlgorithmType] << endl;
    cout << "\nInput file: " << argv[3] << endl;
    cout << "Input size: " << size << endl;
    cout << "---------------------------------\n";
    PrintResult(Time, CountCompare, OutputType);
    WriteFile("output.txt", a, size);

    delete[] a;
}

void Command_2(char *argv[])
{
    int size = atoi(argv[3]);
    int OutputType;
    int dataType;
    int AlgorithmType;
    double Time = 0;
    long long CountCompare = 0;
    bool Success = true;

    // Get output Type(Output parameter)
    OutputType = GetOutputType(argv[5]);
    if (OutputType == -1)
        return;

    // Get DataType
    dataType = GetDataType(argv[4]);
    if (dataType == -1)
        return;

    AlgorithmType = GetAlgorithmType(argv[2]);
    if (AlgorithmType == -1)
        return;

    // Creat Array from order
    int *a = new int[size];
    GenerateData(a, size, dataType);

    // Write down the generated input to the "input.txt" file.
    WriteFile("input.txt", a, size);

    // choose algorithm
    SortArray(a, size, sortingFunctions[AlgorithmType], sortingTimeFunctions[AlgorithmType], CountCompare, Time, OutputType);
    if (!Success)
    {
        delete[] a;
        return;
    }

    // result
    cout << "Algorithm: " << Algorithm[AlgorithmType];
    cout << "\ninput size : " << size << endl;
    cout << "Input order: " << Order[dataType] << endl;
    cout << "---------------------------------\n";
    PrintResult(Time, CountCompare, OutputType);
    WriteFile("output.txt", a, size);

    // free array
    delete[] a;
}

void Command_3(char *argv[])
{
    int size = atoi(argv[3]);
    int OutputType;
    int AlgorithmType;
    double Time = 0;
    long long CountCompare = 0;
    bool Success = true;

    OutputType = GetOutputType(argv[4]);
    if (OutputType == -1)
        return;

    AlgorithmType = GetAlgorithmType(argv[2]);
    if (AlgorithmType == -1)
        return;

    int *a = new int[size];

    cout << "Algorithm: " << Algorithm[AlgorithmType];
    cout << "\nInput size: " << size << endl;

    for (int i = 0; i < 4; i++)
    {

        GenerateData(a, size, i);
        string temp = "input_";
        temp += to_string(i + 1);
        temp += ".txt";
        WriteFile(temp.c_str(), a, size);

        SortArray(a, size, sortingFunctions[AlgorithmType], sortingTimeFunctions[AlgorithmType], CountCompare, Time, OutputType);
        if (!Success)
            break;

        cout << "Input order: " << Order[i] << endl;
        cout << "---------------------------------\n";
        PrintResult(Time, CountCompare, OutputType);
        cout << "\n";
    }
    delete[] a;
}

void Command_4(char *argv[])
{
    int *a, *b;
    int size;
    int AlgorithmType1, AlgorithmType2;
    double Time1 = 0, Time2 = 0;
    long long CountCompare1 = 0, CountCompare2 = 0;

    bool Success = true;

    // Read array from file
    ReadFile(a, size, argv[4]);
    b = CopyArr(a, size);

    AlgorithmType1 = GetAlgorithmType(argv[2]);
    AlgorithmType2 = GetAlgorithmType(argv[3]);
    if (AlgorithmType1 == -1 || AlgorithmType2 == -1)
        return;

    // Sort Array
    SortArray(a, size, sortingFunctions[AlgorithmType1], sortingTimeFunctions[AlgorithmType1], CountCompare1, Time1, 2);
    SortArray(a, size, sortingFunctions[AlgorithmType2], sortingTimeFunctions[AlgorithmType2], CountCompare2, Time2, 2);
    if (!Success)
        return;

    // Result
    cout << "Algorithm: " << Algorithm[AlgorithmType1] << " | " << Algorithm[AlgorithmType2] << endl;
    cout << "\nInput file: " << argv[4] << endl;
    cout << "Input size: " << size << endl;
    cout << "---------------------------------\n";
    cout << "Running time: " << Time1 << " | " << Time2 << endl;
    cout << "Comparisions: " << CountCompare1 << " | " << CountCompare2 << endl;

    // free array
    delete[] a;
    delete[] b;
}

void Command_5(char *argv[])
{
    int *a, *b;
    int dataType;
    int AlgorithmType1, AlgorithmType2;
    int size = atoi(argv[4]);
    double Time1 = 0, Time2 = 0;
    long long CountCompare1 = 0, CountCompare2 = 0;
    bool Success = true;

    // Get datatype for array
    dataType = GetDataType(argv[5]);
    if (dataType == -1)
        return;

    AlgorithmType1 = GetAlgorithmType(argv[2]);
    AlgorithmType2 = GetAlgorithmType(argv[3]);
    if (AlgorithmType1 == -1 || AlgorithmType2 == -1)
        return;

    // Creat Array from array
    a = new int[size];
    GenerateData(a, size, dataType);
    b = CopyArr(a, size);

    // Write down the generated input to the "input.txt" file.
    WriteFile("input.txt", a, size);

    // Sort Array
    SortArray(a, size, sortingFunctions[AlgorithmType1], sortingTimeFunctions[AlgorithmType1], CountCompare1, Time1, 2);
    SortArray(a, size, sortingFunctions[AlgorithmType2], sortingTimeFunctions[AlgorithmType2], CountCompare2, Time2, 2);
    if (!Success)
        return;

    // print result
    cout << "Algorithm: " << Algorithm[AlgorithmType1] << " | " << Algorithm[AlgorithmType2] << endl;
    cout << "\nInput size : " << size << endl;
    cout << "Input order: " << Order[dataType] << endl;
    cout << "---------------------------------\n";
    cout << "Running time: " << Time1 << " | " << Time2 << endl;
    cout << "Comparisions: " << CountCompare1 << " | " << CountCompare2 << endl;

    delete[] a;
    delete[] b;
}