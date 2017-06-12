#include <stdio.h>
#include <string.h>

long long ary[501], value[501], dp[501][501], slash[501];

long long max(long long p, long long q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int count, m, k, i, j, p, q;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &k);
		memset(dp, 0, sizeof(dp));
		for(i=1, m++; i<m; i++)
		{
			scanf("%d", &ary[i]);
			value[i] = ary[i] + value[i-1];
			dp[i][1] = value[i];
			for(j=2; j<=k; j++)
			{
				if(dp[i-1][j-1])
				{
					dp[i][j] = max(dp[i-1][j-1], value[i]-value[i-1]);
					for(p=i-2; p>0; p--)
					{
						if(value[i] - value[p] > dp[i][j] || !dp[p][j-1])
						{
							break;
						}
						if(max(dp[p][j-1], value[i]-value[p]) <= dp[i][j])
						{
							dp[i][j] = max(dp[p][j-1], value[i]-value[p]);
						}
					}
					/*printf("dp[%d][%d] = %d, last[%d][%d] = %d %d;\n", i, j, dp[i][j], i, j, last[i][j]);*/
				}
				else
				{
					break;
				}
			}
		}
		memset(slash, 0, sizeof(slash));
		for(i=m-1, j=k-1, p=dp[m-1][k], q=0; i>-1; i--)
		{
			if((q += ary[i]) > p || i == j)
			{
				slash[i+1] = 1;
				q = ary[i];
				j--;
			}
		}
		printf("%lld", ary[1]);
		for(i=2; i<m; i++)
		{
			if(slash[i])
			{
				printf(" / %lld", ary[i]);
			}
			else
			{
				printf(" %lld", ary[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
