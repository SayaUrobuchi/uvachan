#include <stdio.h>
#include <string.h>

int tbl[128], tt[128];
char s[1024];
const char *pat = "MARGIT";

int main()
{
	int i, d, res, count;
	tt['M'] = 1;
	tt['A'] = 3;
	tt['R'] = 2;
	tt['G'] = 1;
	tt['I'] = 1;
	tt['T'] = 1;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		memset(tbl, 0, sizeof(tbl));
		for (i=0; s[i]; i++)
		{
			tbl[s[i]]++;
		}
		res = 2147483647;
		for (i=0; pat[i]; i++)
		{
			d = tbl[pat[i]] / tt[pat[i]];
			if (d < res)
			{
				res = d;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
