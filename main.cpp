#include "main.h"

bool CheckNumber(char *str)
{
    int size = strlen(str);
    for (int i = 0; i < size; i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{

    // algorithm mode
    if (!strcmp(argv[1], "-a"))
    {
        cout << "ALGORITHM MODE \n";
        // this for command 2
        if (argc == 6)
            Command_2(argv);
        // this for command 3
        else if (CheckNumber(argv[3]))
            Command_3(argv);
        // this for command 1
        else
            Command_1(argv);
    }
    // compare mode
    else
    {
        cout << "COMPARE MODE \n";
        // this is for command 5
        if (argc == 6)
            Command_5(argv);
        // this is for command 4
        else
            Command_4(argv);
    }
}