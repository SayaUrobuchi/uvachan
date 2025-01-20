#include <iostream>
using namespace std;

const int N = 128;

char buf[2][N];

int main()
{
	scanf("%s%s", buf[0], buf[1]);
	string a = buf[0];
	string b = buf[1];
	int res;
	if (a.size() != b.size())
	{
		res = (int)a.size() - (int)b.size();
	}
	else
	{
		if (a < b)
		{
			res = -1;
		}
		else if (a == b)
		{
			res = 0;
		}
		else
		{
			res = 1;
		}
	}
	if (res < 0)
	{
		puts("LESS");
	}
	else if (res == 0)
	{
		puts("EQUAL");
	}
	else
	{
		puts("GREATER");
	}
	return 0;
}
