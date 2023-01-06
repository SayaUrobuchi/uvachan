#include <iostream>
#include <cstring>
using namespace std;

const int NUM_STR = 4;

const string str[] = {"dream", "dreamer", "erase", "eraser"};

int main()
{
	int i, j, k;
	bool is_pos;
	string s;
	getline(cin, s);
	for (i=s.size(), is_pos=true; i>0&&is_pos; i=k)
	{
		for (j=0; j<NUM_STR; j++)
		{
			if (i >= str[j].size() && strcmp(str[j].c_str(), s.c_str()+(i-str[j].size())) == 0)
			{
				break;
			}
		}
		if (j < NUM_STR)
		{
			k = i - str[j].size();
			s.resize(k);
		}
		else
		{
			is_pos = false;
		}
	}
	if (!is_pos)
	{
		puts("NO");
	}
	else
	{
		puts("YES");
	}
	return 0;
}