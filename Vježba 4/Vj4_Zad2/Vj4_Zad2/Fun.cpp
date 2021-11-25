#include "Header.hpp"

void latinise(vector<string>& v)
{
	int len = v.size(), el = 2, j = 0;
	string str = v[el];
	char str2[100];
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if ((str[i] == ' ') || (str[i] == ',') || (str[i] == '.') || (str[i] == '!') || (str[i] == '?') || (str[i] == '\0'))
		{
			str2[j] = str[i];
			++j;
		}
		else if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u')
		{
			for(;;)
			{
				if ((str[i] == ' ') || (str[i] == ',') || (str[i] == '.') || (str[i] == '!') || (str[i] == '?') || (str[i] == '\0'))
					break;
				str2[j] = str[i];
				++i;
				++j;
			}
			str2[j] = 'h';
			++j;
			str2[j] = 'a';
			++j;
			str2[j] = 'y';
			++j;
			--i;
		}
		else
		{
			int br = 0, off = 0;
			for (;;)
			{
				if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u')
					break;
				++br;
				++i;
			}
			for (;;)
			{
				if ((str[i] == ' ') || (str[i] == ',') || (str[i] == '.') || (str[i] == '!') || (str[i] == '?') || (str[i] == '\0'))
					break;
				if (j == 0)
					str2[j] = toupper(str[i]);
				else
					str2[j] = str[i];
				++i;
				++j;
				++off;
			}
			for (int k = 0; k < br; ++k)
			{
				str2[j] = tolower(str[i - off - br]);
				++j;
				++i;
			}
			i -= br;
			str2[j] = 'a';
			++j;
			str2[j] = 'y';
			++j;
			--i;
		}
	}
	str2[j] = '\0';
	v[el] = str2;
}

void printVec(vector<string> v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i] << endl;
	cout << endl;
}