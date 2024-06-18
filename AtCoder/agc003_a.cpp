#include <iostream>
using namespace std;

const int N = 1024;
const char *key = "NSEW";
const int NS = 0b0011;
const int EW = 0b1100;

int tbl[128];
char s[N];

int main()
{
	int i;
	for (i=0; key[i]; i++)
	{
		tbl[key[i]] = (1 << i);
	}
	scanf("%s", s);
	int st = 0;
	for (i=0; s[i]; i++)
	{
		st |= tbl[s[i]];
	}
	bool ans = ((st & NS) == NS || !(st & NS))
			 && ((st & EW) == EW || !(st & EW));
	puts(ans ? "Yes" : "No");
	return 0;
}
