#include <stdio.h>

int ary[25][25];

int main()
{
	int n, m, i, j, k;
	while(scanf("%d%d", &m, &n) == 2)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		for (j=0; j<m; j++)
		{
			for (i=n-1, k=n-1; i>=0; i--)
			{
				if (ary[i][j] == 1)
				{
					ary[k][j] = ary[i][j];
					k--;
				}
			}
			for (; k>=0; k--)
			{
				ary[k][j] = 0;
			}
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				if (j)
				{
					printf(" ");
				}
				printf("%d", ary[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}