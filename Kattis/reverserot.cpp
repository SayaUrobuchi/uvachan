#include <stdio.h>
#include <string.h>
#include <algorithm>

const int M = 28;
const char *key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
int tbl[128];

char s[1024];

int main()
{
	int n, i;
	for (i=0; i<M; i++)
	{
		tbl[key[i]] = i;
	}
	while (scanf("%d%s", &n, s) == 2)
	{
		if (n == 0)
		{
			break;
		}
		std::reverse(s, s+strlen(s));
		for (i=0; s[i]; i++)
		{
			s[i] = key[ (tbl[s[i]]+n)%M ];
		}
		puts(s);
	}
	return 0;
}
