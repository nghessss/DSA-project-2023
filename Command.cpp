#include "main.h"

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

int *CopyArr(int *a, int n)
{
    int *b = new int[n];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    return b;
}

void SortArr(int *&a, int n, char *Algorithm, long long &CountCompare, double &Time, int OutputType, bool &Success)
{
    CountCompare = 0;
    Time = 0;

    if (!strcmp(Algorithm, "selection-sort"))
    {
        if (OutputType == 0)
            selectionSortTime(a, n, Time);
        else if (OutputType == 1)
            selectionSortCompare(a, n, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            selectionSortTime(a, n, Time);
            selectionSortCompare(b, n, CountCompare);

            delete[] b;
        }
    }
    else if (!strcmp(Algorithm, "insertion-sort"))
    {
        if (OutputType == 0)
            insertionSortTime(a, n, Time);
        else if (OutputType == 1)
            insertionSortCompare(a, n, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            insertionSortTime(a, n, Time);
            insertionSortCompare(b, n, CountCompare);

            delete[] b;
        }
    }
    else if (!strcmp(Algorithm, "bubble-sort"))
    {
        if (OutputType == 0)
            bubbleSortTime(a, n, Time);
        else if (OutputType == 1)
            bubbleSortCompare(a, n, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            bubbleSortTime(a, n, Time);
            bubbleSortCompare(b, n, CountCompare);

            delete[] b;
        }
    }
    else if (!strcmp(Algorithm, "shaker-sort"))
    {
        if (OutputType == 0)
            shakerSortTime(a, n, Time);
        else if (OutputType == 1)
            shakerSortCompare(a, n, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            shakerSortTime(a, n, Time);
            shakerSortCompare(b, n, CountCompare);

            delete[] b;
        }
    }
    else if (!strcmp(Algorithm, "shell-sort"))
    {
        if (OutputType == 0)
            shellSortTime(a, n, Time);
        else if (OutputType == 1)
            shellSortCompare(a, n, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            shellSortTime(a, n, Time);
            shellSortCompare(b, n, CountCompare);

            delete[] b;
        }
    }
    else if (!strcmp(Algorithm, "heap-sort"))
    {
        if (OutputType == 0)
            heapSortTime(a, n, Time);
        else if (OutputType == 1)
            heapSortCompare(a, n, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            heapSortTime(a, n, Time);
            heapSortCompare(b, n, CountCompare);

            delete[] b;
        }
    }
    else if (!strcmp(Algorithm, "merge-sort"))
    {
        if (OutputType == 0)
            mergeSortTime(a, 0, n - 1, Time);
        else if (OutputType == 1)
            mergeSortCompare(a, 0, n - 1, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            mergeSortTime(a, 0, n - 1, Time);
            mergeSortCompare(b, 0, n, CountCompare);

            delete[] b;
        }
    }
    else if (!strcmp(Algorithm, "quick-sort"))
    {
        if (OutputType == 0)
            quickSortTime(a, n, Time);
        else if (OutputType == 1)
            quickSortCompare(a, n, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            quickSortTime(a, n, Time);
            quickSortCompare(b, n, CountCompare);

            delete[] b;
        }
    }
    else if (!strcmp(Algorithm, "counting-sort"))
    {
        if (OutputType == 0)
            countingSortTime(a, n, Time);
        else if (OutputType == 1)
            countingSortCompare(a, n, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            countingSortTime(a, n, Time);
            countingSortCompare(b, n, CountCompare);

            delete[] b;
        }
    }
    else if (!strcmp(Algorithm, "radix-sort"))
    {
        if (OutputType == 0)
            radixSortTime(a, n, Time);
        else if (OutputType == 1)
            radixSortCompare(a, n, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            radixSortTime(a, n, Time);
            radixSortCompare(b, n, CountCompare);

            delete[] b;
        }
    }
    else if (!strcmp(Algorithm, "flash-sort"))
    {
        if (OutputType == 0)
            flashSortTime(a, n, Time);
        else if (OutputType == 1)
            flashSortCompare(a, n, CountCompare);
        else
        {
            int *b = CopyArr(a, n);
            flashSortTime(a, n, Time);
            flashSortCompare(b, n, CountCompare);

            delete[] b;
        }
    }
    else
    {
        cout << "wrong ahgorithm format, please try again\n";
        Success = false;
    }
}

void PrintOrder(int dataType)
{
    cout << "input order: ";
    if (dataType == 0)
        cout << " Randomize \n";
    else if (dataType == 1)
        cout << " Nearly Sorted \n";
    else if (dataType == 2)
        cout << " Sorted \n";
    else
        cout << " Reversed \n";
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

void PrintAlgorithm(char *Algorithm)
{
    if (!strcmp(Algorithm, "selection-sort"))
        cout << "Selection Sort";
    else if (!strcmp(Algorithm, "insertion-sort"))
        cout << "Insertion Sort";
    else if (!strcmp(Algorithm, "bubble-sort"))
        cout << "Bubble Sort";
    else if (!strcmp(Algorithm, "shaker-sort"))
        cout << "Shaker Sort";
    else if (!strcmp(Algorithm, "shell-sort"))
        cout << "Shell Sort";
    else if (!strcmp(Algorithm, "heap-sort"))
        cout << "Heap Sort";
    else if (!strcmp(Algorithm, "merge-sort"))
        cout << "Merge Sort";
    else if (!strcmp(Algorithm, "quick-sort"))
        cout << "Quick Sort";
    else if (!strcmp(Algorithm, "counting-sort"))
        cout << "Counting Sort";
    else if (!strcmp(Algorithm, "radix-sort"))
        cout << "Radix Sort";
    else if (!strcmp(Algorithm, "flash-sort"))
        cout << "Flash Sort";
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
    int size;
    double Time = 0;
    long long CountCompare = 0;
    bool Success = true;

    OutputType = GetOutputType(argv[4]);
    if (OutputType == -1)
        return;

    // Read Array From file
    ReadFile(a, size, argv[3]);

    // Sort Array
    SortArr(a, size, argv[2], CountCompare, Time, OutputType, Success);
    if (!Success)
        return;

    // Result
    cout << "Algorithm: ";
    PrintAlgorithm(argv[2]);
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

    // Creat Array from order
    int *a = new int[size];
    GenerateData(a, size, dataType);

    // Write down the generated input to the "input.txt" file.
    WriteFile("input.txt", a, size);

    // choose algorithm
    SortArr(a, size, argv[2], CountCompare, Time, OutputType, Success);
    if (!Success)
    {
        delete[] a;
        return;
    }

    // result
    cout << "Algorithm: ";
    PrintAlgorithm(argv[2]);
    cout << "\ninput size : " << size << endl;
    PrintOrder(dataType);
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
    double Time = 0;
    long long CountCompare = 0;
    bool Success = true;

    OutputType = GetOutputType(argv[4]);
    if (OutputType == -1)
        return;

    int *a = new int[size];

    cout << "Algorithm: ";
    PrintAlgorithm(argv[2]);
    cout << "\nInput size: " << size << endl;

    for (int i = 0; i < 4; i++)
    {

        GenerateData(a, size, i);
        string temp = "input_";
        temp += to_string(i + 1);
        temp += ".txt";
        WriteFile(temp.c_str(), a, size);
        
        SortArr(a, size, argv[2], CountCompare, Time, OutputType, Success);
        if (!Success)
            break;

        PrintOrder(i);
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
    double Time1 = 0, Time2 = 0;
    long long CountCompare1 = 0, CountCompare2 = 0;

    bool Success = true;

    // Read array from file
    ReadFile(a, size, argv[4]);
    b = CopyArr(a, size);

    // Sort Array
    SortArr(a, size, argv[2], CountCompare1, Time1, 2, Success);
    SortArr(b, size, argv[3], CountCompare2, Time2, 2, Success);
    if (!Success)
        return;

    // Result
    cout << "Algorithm: ";
    PrintAlgorithm(argv[2]);
    cout << " | ";
    PrintAlgorithm(argv[3]);
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
    int size = atoi(argv[4]);
    double Time1 = 0, Time2 = 0;
    long long CountCompare1 = 0, CountCompare2 = 0;
    bool Success = true;

    // Get datatype for array
    dataType = GetDataType(argv[5]);
    if (dataType == -1)
        return;

    // Creat Array from array
    a = new int[size];
    GenerateData(a, size, dataType);
    b = CopyArr(a, size);

    // Write down the generated input to the "input.txt" file.
    WriteFile("input.txt", a, size);

    // Sort Array
    SortArr(a, size, argv[2], CountCompare1, Time1, 2, Success);
    SortArr(b, size, argv[3], CountCompare2, Time2, 2, Success);
    if (!Success)
        return;

    // print result
    cout << "Algorithm: ";
    PrintAlgorithm(argv[2]);
    cout << " | ";
    PrintAlgorithm(argv[3]);
    cout << "\nInput size : " << size << endl;
    PrintOrder(dataType);
    cout << "---------------------------------\n";
    cout << "Running time: " << Time1 << " | " << Time2 << endl;
    cout << "Comparisions: " << CountCompare1 << " | " << CountCompare2 << endl;

    delete[] a;
    delete[] b;
}