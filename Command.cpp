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

// Hàm này dùng để chuẩn hóa với dữ liệu đã cho theo thứ tự của thầy thông.
int ChangeDataType(int DataType)
{
    switch (DataType)
    {
    case 0:
        return 0;
    case 1:
        return 3;
    case 2:
        return 1;
    case 3:
        return 2;
    default:
        return -1;
    }

}

void SortArr(int *&a, int n, char *Algorithm, int &CountCompare, int &Time, int OutputType, bool &Success)
{
    CountCompare = 0;
    Time = 0;

    if (!strcmp(Algorithm, "selection-sort"))
    {
        // call Selection Sort
    }
    else if (!strcmp(Algorithm, "insertion-sort"))
    {
        // call insert sort
    }
    else if (!strcmp(Algorithm, "bubble-sort"))
    {
        // call bubble sort
    }
    else if (!strcmp(Algorithm, "shaker-sort"))
    {
        // call shaker sort
    }
    else if (!strcmp(Algorithm, "shell-sort"))
    {
        // call shell sort
    }
    else if (!strcmp(Algorithm, "heap-sort"))
    {
        // call heap sort
    }
    else if (!strcmp(Algorithm, "merge-sort"))
    {
        // call merge sort
    }
    else if (!strcmp(Algorithm, "quick-sort"))
    {
        // call quick sort
    }
    else if (!strcmp(Algorithm, "counting-sort"))
    {
        // call counting sort
    }
    else if (!strcmp(Algorithm, "radix-sort"))
    {
        // call radix sort
    }
    else if (!strcmp(Algorithm, "flash-sort"))
    {
        // call flash sort
    }
    else
    {
        cout << "wrong ahgorithm format, please try again\n";
        Success = false;
    }
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

void PrintResult(int Time, int CountCompare, int OutputType)
{
    if (OutputType == 0)
        cout << "Running Time : " << Time << endl;
    // compare only
    else if (OutputType == 1)
        cout << "Running Time : " << CountCompare << endl;
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
    int size;
    int Time = 0;
    int CountCompare = 0;
    bool Success = true;

    OutputType = GetOutputType(argv[4]);
    if (OutputType == -1)
        return;

    //Read Array From file
    ReadFile(a, size, argv[3]);

    //Sort Array
    SortArr(a, size, argv[2], CountCompare, Time, OutputType, Success);
    if (!Success)
        return;

    // Result
    cout << "Input file : " << argv[3] << endl;
    cout << "Input size : " << size << endl;
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
    int Time = 0;
    int CountCompare = 0;
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
    GenerateData(a, size, ChangeDataType(dataType));

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
    cout << "input size : " << size << endl;
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
    int Time = 0;
    int CountCompare = 0;
    bool Success = true;

    OutputType = GetOutputType(argv[4]);
    if (OutputType == -1)
        return;

    int *a = new int[size];

    for (int i = 0; i < 4; i++)
    {
        GenerateData(a, size, ChangeDataType(i));
        SortArr(a, size, argv[2], CountCompare, Time, OutputType, Success);
        if (!Success)
            break;

        PrintOrder(i);
        cout << "---------------------------------\n";
        PrintResult(Time, CountCompare, OutputType);
        cout << "\n";

        // Get name of file
        string temp = "input_";
        temp += to_string(i + 1);
        temp += ".txt";
        WriteFile(temp.c_str(), a, size);
    }
    delete[] a;
}