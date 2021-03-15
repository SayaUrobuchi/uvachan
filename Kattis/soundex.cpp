#include <iostream>

const char *key[] = {"", "BFPV", "CGJKQSXZ", "DT", "L", "NM", "R"};
int tbl[128];
char s[1024];

int main()
{
	int i, j, c, last;
	for (i=1; i<=6; i++)
	{
		for (j=0; key[i][j]; j++)
		{
			tbl[key[i][j]] = i;
		}
	}
	while (scanf("%s", s) == 1)
	{
		for (i=0, last=0; s[i]; i++)
		{
			c = tbl[s[i]];
			if (c)
			{
				if (last != c)
				{
					printf("%d", c);
				}
			}
			last = c;
		}
		puts("");
	}
	return 0;
}