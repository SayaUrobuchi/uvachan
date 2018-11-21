#include <stdio.h>

int dp[102][102][102];
char str[20][105];

int max(int p, int q)
{
	return p>q ? p : q;
}

int lcs(char *p, char *q, char *r)
{
	int i, j, k;
	for(i=0; p[i]; i++)
	{
		for(j=0; q[j]; j++)
		{
			for(k=0; r[k]; k++)
			{
				if(p[i] == q[j] && q[j] == r[k])
				{
					dp[i+1][j+1][k+1] = dp[i][j][k] + 1;
				}
				else
				{
					dp[i+1][j+1][k+1] = max(dp[i][j+1][k+1], max(dp[i+1][j][k+1], dp[i+1][j+1][k]));
				}
			}
		}
	}
	return dp[i][j][k];
}

int main()
{
	int n, i, j, k, ans, temp;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s", str[i]);
		}
		for(i=0, ans=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				for(k=j+1; k<n; k++)
				{
					if((temp=lcs(str[i], str[j], str[k])) > ans)
					{
						ans = temp;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
