#include <stdio.h>

int matrix[101][101];

int main()
{
	int n, m, i, j;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}
		for(j=0; j<m; j++)
		{
			printf("%d", matrix[0][j]);
			for(i=1; i<n; i++)
			{
				printf(" %d", matrix[i][j]);
			}
			putchar(10);
		}
	}
	return 0;
}
