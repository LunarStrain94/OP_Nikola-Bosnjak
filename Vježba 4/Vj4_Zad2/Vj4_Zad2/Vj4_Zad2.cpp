#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "Header.hpp"
using namespace std;

int main()
{
    srand(time(NULL));
    vector<string> v;
    v.push_back("What time is it?");
    v.push_back("It's quarter past eleven.");
    v.push_back("My name is Isaac!");
    v.push_back("Can you help me?");
    latinise(v);
    printVec(v);
}