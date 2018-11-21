#include <stdio.h>
#include <string.h>

long long dp[105][105];

int main()
{
	int n, i, j, k, l;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%I64d", &dp[i][i]);
		}
		for(k=1; k<n; k++)
		{
			for(i=0, j=i+k; j<n; i++, j++)
			{
				dp[i][j] = -1;
				if(k % 2)
				{
					for(l=i; l<j; l++)
					{
						if(dp[i][j] < dp[i][l] + dp[l+1][j])
						{
							dp[i][j] = dp[i][l] + dp[l+1][j];
						}
					}
				}
				else
				{
					for(l=i; l<j; l++)
					{
						if(dp[i][j] < dp[i][l] * dp[l+1][j])
						{
							dp[i][j] = dp[i][l] * dp[l+1][j];
						}
					}
				}
			}
		}
		printf("%I64d\n", dp[0][n-1]);
	}
	return 0;
}
