#include <stdio.h>
#include <string.h>

int dp[500][500];

int main()
{
	int cas, count, n, m, i, j, k, l, temp;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(dp, 0, sizeof(dp));
		for(l=1; l<n; l++)
		{
			for(i=0, j=i+l; j<n; i++, j++)
			{
				dp[i][j] = 2147483647;
				for(k=i; k<=j; k++)
				{
					if((temp=dp[i][k-1]+dp[k+1][j]+(l+1)*(k+1+m)) < dp[i][j])
					{
						dp[i][j] = temp;
					}
				}
			}
		}
		printf("Case %d: %d\n", ++cas, dp[0][n-1]);
	}
	return 0;
}
