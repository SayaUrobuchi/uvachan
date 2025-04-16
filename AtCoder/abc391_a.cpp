#include <iostream>
using namespace std;

const char *KEY = "NESW";
const int N = 8;

char buf[N];
char tbl[128];

int main()
{
	int i;
	for (i=0; KEY[i]; i++)
	{
		tbl[ KEY[i] ] = KEY[(i+2)&3];
	}
	scanf("%s", buf);
	for (i=0; buf[i]; i++)
	{
		buf[i] = tbl[ buf[i] ];
	}
	puts(buf);
	return 0;
}
