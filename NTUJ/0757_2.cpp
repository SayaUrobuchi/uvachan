#include <stdio.h>
#include <string.h>

int mnum[1005], map[1005][1005], has[1005][1005];
int used[1005], len[1005];
unsigned long long int dp[1005];

unsigned long long recurs(int t)
{
	int i, p, nx;
	if(used[t])
	{
		return dp[t];
	}
	used[t] = 1;
	if(t == 1)
	{
		return dp[t]=1;
	}
	dp[t] = 0;
	for(i=0; i<mnum[t]; i++)
	{
		dp[t] += recurs(map[t][i]);
	}
	return dp[t];
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
		printf("%llu\n", recurs(n));
		scanf("%d", &p);
		if(p == -1)
		{
			break;
		}
	}
	return 0;
}
