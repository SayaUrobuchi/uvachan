#include <iostream>
#include <algorithm>
using namespace std;

int tbl[128];
char s[131072];

int main()
{
	int n;
	tbl['0'] = '0';
	tbl['1'] = '1';
	tbl['6'] = '9';
	tbl['8'] = '8';
	tbl['9'] = '6';
	while (scanf("%s", s) == 1)
	{
		for (n=0; s[n]; s[n]=tbl[s[n]], ++n);
		reverse(s, s+n);
		puts(s);
	}
	return 0;
}

