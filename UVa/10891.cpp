#include <stdio.h>

int sum[100][100], dp[100][100];

int main()
{
	int n, i, j, k, l, tmp, tmp2, max;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &dp[i][i]);
			sum[i][i] = dp[i][i];
		}
		for(l=1; l<n; l++)
		{
			for(i=0, j=l; j<n; i++, j++)
			{
				sum[i][j] = sum[i][i] + sum[i+1][j];
				dp[i][j] = sum[i][j];
				for(k=i; k<j; k++)
				{
					if(sum[i][k] - dp[k+1][j] > dp[i][j])
					{
						dp[i][j] = sum[i][k] - dp[k+1][j];
					}
					if(sum[k+1][j] - dp[i][k] > dp[i][j])
					{
						dp[i][j] = sum[k+1][j] - dp[i][k];
					}
				}
				/*printf("%d %d %d\n", i, j, dp[i][j]);*/
			}
		}
		printf("%d\n", dp[0][n-1]);
	}
	return 0;
}
