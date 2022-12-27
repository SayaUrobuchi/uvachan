#include <iostream>
using namespace std;

char buf[131072];
bool tbl[128];

int main()
{
	int i, c;
	scanf("%s", buf);
	for (i=0; buf[i]; i++)
	{
		tbl[buf[i]] = true;
	}
	for (i='a', c=0; i<='z'; i++)
	{
		if (!tbl[i])
		{
			++c;
			putchar(i);
			break;
		}
	}
	if (c)
	{
		puts("");
	}
	else
	{
		puts("None");
	}
	return 0;
}