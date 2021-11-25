#include "Header.hpp"
#pragma warning(disable : 4996)
using namespace std;

void fixStr(char* str)
{
    int j = 0;
    char str2[100];
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
            i++;
        else if ((str[i] == ' ' && str[i + 1] == ',') || (str[i] == ' ' && str[i + 1] == '.'))
        {
            str2[j] = str[i + 1];
            j++;
            str2[j] = str[i];
            i++;
        }
        else
        {
            str2[j] = str[i];
            j++;
        }
    }
    str2[j] = '\0';
    strcpy(str, str2);
}

void printStr(char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        cout << str[i];
}