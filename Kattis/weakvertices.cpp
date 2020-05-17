#include <stdio.h>

int used[32], ary[32][32];

int main()
{
	int n, i, j, k, first;
	while (scanf("%d", &n) == 1)
	{
		if (n < 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			used[i] = 0;
			for (j=0; j<n; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<n&&!used[i]; j++)
			{
				if (i != j && ary[i][j])
				{
					for (k=0; k<n&&!used[i]; k++)
					{
						if (i != k && k != j && ary[i][k] && ary[j][k])
						{
							used[i] = used[j] = used[k] = 1;
						}
					}
				}
			}
		}
		for (i=0, first=1; i<n; i++)
		{
			if (!used[i])
			{
				if (!first)
				{
					putchar(' ');
				}
				first = 0;
				printf("%d", i);
			}
		}
		puts("");
	}
	return 0;
}
