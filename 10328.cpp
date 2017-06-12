#include <stdio.h>
#include <string.h>

int dp[101][101][5], num[101][101], tbl[101][5], tnum[101], temp[5];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, m, i, j, k, l;
	tbl[0][0] = 1;
	tnum[0] = 1;
	for(i=1; i<101; i++)
	{
		for(j=0; j<tnum[i-1]; j++)
		{
			tbl[i][j] += tbl[i-1][j] + tbl[i-1][j];
			if(tbl[i][j] > 999999999)
			{
				tbl[i][j+1]++;
				tbl[i][j] -= 1000000000;
			}
		}
		for(; tbl[i][j]; j++)
		{
			if(tbl[i][j] > 999999999)
			{
				tbl[i][j+1]++;
				tbl[i][j] -= 1000000000;
			}
		}
		tnum[i] = j;
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));
		dp[0][0][0] = 1;
		num[0][0] = 1;
		for(i=1; i<=n; i++)
		{
			for(j=0; j<i&&j<m; j++)
			{
				for(k=0; k<num[i-1][j]; k++)
				{
					dp[i][0][k] += dp[i-1][j][k];
					if(dp[i][0][k] > 999999999)
					{
						dp[i][0][k+1]++;
						dp[i][0][k] -= 1000000000;
					}
				}
				for(; dp[i][0][k]; k++)
				{
					if(dp[i][0][k] > 999999999)
					{
						dp[i][0][k+1]++;
						dp[i][0][k] -= 1000000000;
					}
				}
				num[i][0] = max(num[i][0], k);
			}
			for(j=1; j<=i&&j<m; j++)
			{
				num[i][j] = num[i-1][j-1];
				for(k=0; k<num[i-1][j-1]; k++)
				{
					dp[i][j][k] = dp[i-1][j-1][k];
				}
			}
		}
		l = tnum[n];
		for(i=0; i<l; i++)
		{
			temp[i] = tbl[n][i];
		}
		temp[i] = 0;
		for(j=0; j<m; j++)
		{
			for(k=0; k<num[n][j]; k++)
			{
				temp[k] -= dp[n][j][k];
				if(temp[k] < 0)
				{
					temp[k+1]--;
					temp[k] += 1000000000;
				}
			}
			for(; temp[k]; k++)
			{
				if(temp[k] < 0)
				{
					temp[k+1]--;
					temp[k] += 1000000000;
				}
			}
			if(!temp[l-1])
			{
				l--;
			}
		}
		printf("%d", temp[l-1]);
		for(i=l-2; i>-1; i--)
		{
			printf("%09d", temp[i]);
		}
		printf("\n");
	}
	return 0;
}
