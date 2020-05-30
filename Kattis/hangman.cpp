#include <stdio.h>

int tbl[128];
char s[128], buf[128];

int main()
{
	int n, i, hp;
	while (scanf("%s%s", s, buf) == 2)
	{
		for (i='A'; i<='Z'; i++)
		{
			tbl[i] = 0;
		}
		for (i=0; s[i]; i++)
		{
			tbl[s[i]]++;
		}
		n = i;
		for (i=0, hp=10; n&&hp; i++)
		{
			if (tbl[buf[i]])
			{
				n -= tbl[buf[i]];
			}
			else
			{
				--hp;
			}
		}
		if (!hp)
		{
			puts("LOSE");
		}
		else
		{
			puts("WIN");
		}
	}
	return 0;
}
