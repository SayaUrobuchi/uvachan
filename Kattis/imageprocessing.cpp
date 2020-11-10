#include <iostream>

int org[32][32], modf[32][32];

int main()
{
	int n, m, p, q, i, j, a, b, t;
	while (scanf("%d%d%d%d", &n, &m, &p, &q) == 4)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%d", &org[i][j]);
			}
		}
		for (i=0; i<p; i++)
		{
			for (j=0; j<q; j++)
			{
				scanf("%d", &modf[i][j]);
			}
		}
		for (i=0; i+p<=n; i++)
		{
			for (j=0; j+q<=m; j++)
			{
				for (a=0, t=0; a<p; a++)
				{
					for (b=0; b<q; b++)
					{
						t += modf[p-a-1][q-b-1] * org[i+a][j+b];
					}
				}
				if (j)
				{
					putchar(' ');
				}
				printf("%d", t);
			}
			puts("");
		}
	}
	return 0;
}
