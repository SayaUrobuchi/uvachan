#include <stdio.h>

int tbl[11][11];
int ary[11];

int main()
{
	int n, m, i, j;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &tbl[0][i]);
		}
		ary[n] = tbl[0][n-1];
		for(i=1; i<n; i++)
		{
			for(j=0; j<n-i; j++)
			{
				tbl[i][j] = tbl[i-1][j+1] - tbl[i-1][j];
				/*printf("%10d", tbl[i][j]);*/
			}
			/*printf("\n");*/
			ary[n-i] = tbl[i][n-i-1];
		}
		scanf("%d", &m);
		for(j=0; j<m; j++)
		{
			/*printf("%10d", ary[1]);*/
			for(i=2; i<=n; i++)
			{
				ary[i] += ary[i-1];
				/*printf("%10d", ary[i]);*/
			}
			/*printf("\n");*/
		}
		printf("Term %d of the sequence is %d\n", n+m, ary[n]);
	}
	return 0;
}
