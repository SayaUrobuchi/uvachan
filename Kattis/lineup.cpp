#include <stdio.h>
#include <string.h>

char nam[32][32];

int main()
{
	int n, i, j, t;
	while (scanf("%d%s", &n, nam[0]) == 2)
	{
		for (i=1, j=3; i<n; i++)
		{
			scanf("%s", nam[i]);
			t = strcmp(nam[i-1], nam[i]);
			if (t < 0)
			{
				j &= ~1;
			}
			else
			{
				j &= ~2;
			}
		}
		if (j == 1)
		{
			puts("DECREASING");
		}
		else if (j == 2)
		{
			puts("INCREASING");
		}
		else
		{
			puts("NEITHER");
		}
	}
	return 0;
}
