#include <stdio.h>
#include <string.h>

int ary[251];
int total[251];
int dp[251][251];

int main()
{
	int n, i, j, k, l;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if(i)
			{
				total[i] = total[i-1] + ary[i];
			}
			else
			{
				total[i] = ary[i];
			}
		}
		memset(dp, 0, sizeof(dp));
		for(k=1; k<n; k++)
		{
			for(i=0, j=i+k; j<n; i++, j++)
			{
				dp[i][j] = 2147483647;
				for(l=i; l<=j; l++)
				{
					if(dp[i][l-1] + dp[l+1][j] - ary[l] < dp[i][j])
					{
						dp[i][j] = dp[i][l-1] + dp[l+1][j] - ary[l];
					}
				}
				if(i)
				{
					dp[i][j] += total[j] - total[i-1];
				}
				else
				{
					dp[i][j] += total[j];
				}
			}
		}
		printf("%d\n", dp[0][n-1]);
	}
	return 0;
}
