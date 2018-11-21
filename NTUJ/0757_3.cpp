#include <stdio.h>
#include <string.h>

int n;
int mnum[1005], map[1005][1005];
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
	if(t == n)
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
	int m, i, p, q;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(mnum, 0, sizeof(mnum));
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			if(q == n && p == 1)
			{
				continue;
			}
			map[p][mnum[p]++] = q;
		}
		memset(used, 0, sizeof(used));
		printf("%llu\n", recurs(1));
		scanf("%d", &p);
		if(p == -1)
		{
			break;
		}
	}
	return 0;
}
