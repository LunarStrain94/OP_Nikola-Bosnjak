#include <iostream>
#include <string>
#include "Header.hpp"
using namespace std;

int main()
{
    char str[100] = "Ja bih    , ako ikako mogu , ovu recenicu napisala ispravno .";
    fixStr(str);
    printStr(str);
}