#include <iostream>
using namespace std;

int main()
{
	char buf[16];
	bool first = true;
	while (scanf("%s", buf) == 1)
	{
		char c = 'A';
		if (*buf == 'L')
		{
			c = '<';
		}
		else if (*buf == 'R')
		{
			c = '>';
		}
		if (!first)
		{
			putchar(' ');
		}
		first = false;
		putchar(c);
	}
	puts("");
	return 0;
}
