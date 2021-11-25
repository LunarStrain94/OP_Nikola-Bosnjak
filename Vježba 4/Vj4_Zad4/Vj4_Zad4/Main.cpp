#include <iostream>
#include <vector>
#include "Header.hpp"
using namespace std;

int main()
{
    vector<int> v;
    inputVec(v);
    printVec(v);
    stuffingBit(v);
    printVec(v);
    unstuffingBit(v);
    printVec(v);
}