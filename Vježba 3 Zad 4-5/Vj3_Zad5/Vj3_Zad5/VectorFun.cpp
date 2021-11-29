#include "Header.hpp"

using namespace std;

int countStr(string str, string str2)
{
	int count = 0;
    size_t nPos = str.find(str2, 0);
    while (nPos != string::npos)
    {
        count++;
        nPos = str.find(str2, nPos + 1);
    }

    return count;
}