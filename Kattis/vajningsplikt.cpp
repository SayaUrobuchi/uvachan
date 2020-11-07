#include <iostream>

const char *key = "NESW";
int tbl[128];
char s0[1024], s1[1024], s2[1024];

int main()
{
	int a, b, c, i;
	for (i=0; key[i]; i++)
	{
		tbl[key[i]] = i;
	}
	while (scanf("%s%s%s", s0, s1, s2) == 3)
	{
		a = tbl[*s0];
		b = tbl[*s1];
		c = tbl[*s2];
		if (b == ((a+2)&3) && c == ((a+3)&3))
		{
			puts("Yes");
		}
		else if (b == ((a+1)&3) && (c == ((a+2)&3) || c == ((a+3)&3)))
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
