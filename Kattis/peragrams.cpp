#include <stdio.h>
#include <string.h>

int tbl[128];
char s[1024];

int main()
{
	int i, k;
	while (scanf("%s", s) == 1)
	{
		memset(tbl, 0, sizeof(tbl));
		for (i=0; s[i]; i++)
		{
			tbl[s[i]]++;
		}
		for (i='a', k=0; i<='z'; i++)
		{
			k += (tbl[i] & 1);
		}
		printf("%d\n", k?k-1:0);
	}
	return 0;
}
