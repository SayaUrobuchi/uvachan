#include <iostream>
using namespace std;

int p;
char s[105];

bool recurs(int t)
{
	char c = s[p++];
	if (c >= 'p' && c <= 't')
	{
		return t & (1 << (c-'p'));
	}
	if (c == 'N')
	{
		return !recurs(t);
	}
	bool a = recurs(t);
	bool b = recurs(t);
	if (c == 'K')
	{
		return a && b;
	}
	if (c == 'A')
	{
		return a || b;
	}
	if (c == 'C')
	{
		return a <= b;
	}
	return a == b;
}

int main()
{
	int i;
	while (scanf("%s", s) == 1)
	{
		if (*s == '0')
		{
			break;
		}
		bool full = true;
		for (i=0; full&&i<(1<<5); i++)
		{
			p = 0;
			full = recurs(i);
		}
		puts(full?"tautology":"not");
	}
	return 0;
}
