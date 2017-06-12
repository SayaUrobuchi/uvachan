#include <stdio.h>
#include <string.h>

int mnum[1005], map[1005][1005], has[1005][1005];
int used[1005], len[1005];
int dp[1005][1005];

int recurs(int t)
{
	int i, p, nx;
	if(used[t])
	{
		return 1;
	}
	used[t] = 1;
	if(t == 1)
	{
		len[t] = 1;
		return dp[t][0]=1;
	}
	dp[t][0] = 0;
	len[t] = 1;
	for(i=0; i<mnum[t]; i++)
	{
		recurs(nx=map[t][i]);
		for(p=0; p<len[t]&&p<len[nx]; p++)
		{
			dp[t][p] += dp[nx][p];
		}
		for(; p<len[nx]; p++)
		{
			dp[t][p] = dp[nx][p];
		}
		if(len[nx] > len[t])
		{
			len[t] = len[nx];
		}
		dp[t][len[t]] = 0;
		for(p=0; p<len[t]; p++)
		{
			if(dp[t][p] >= 10)
			{
				dp[t][p+1]++;
				dp[t][p] -= 10;
			}
		}
		if(dp[t][len[t]])
		{
			len[t]++;
		}
	}
	return 1;
}

int main()
{
	int n, m, i, p, q;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(mnum, 0, sizeof(mnum));
		memset(has, 0, sizeof(has));
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			if(q == n && p == 1)
			{
				continue;
			}
			if(has[q][p])
			{
				continue;
			}
			has[q][p] = 1;
			map[q][mnum[q]++] = p;
		}
		memset(used, 0, sizeof(used));
		recurs(n);
		for(i=len[n]-1; i>=0; i--)
		{
			printf("%d", dp[n][i]);
		}
		printf("\n");
		scanf("%d", &p);
		if(p == -1)
		{
			break;
		}
	}
	return 0;
}
