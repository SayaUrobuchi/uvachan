#include <stdio.h>
#include <string.h>

int n, m;
int dp[131072], used[131072], wei[20], tim[20];

int recurs(int stat);

void dfs(int stat, int mask, int depth, int weight, int time, int last)
{
	int i;
	if(depth)
	{
		if(recurs(mask) + time < dp[stat])
		{
			dp[stat] = recurs(mask)+time;
		}
	}
	for(i=last; i<n; i++)
	{
		if(mask&(1<<i))
		{
			if(weight + wei[i] <= m)
			{
				dfs(stat, mask-(1<<i), depth+1, weight+wei[i], time>tim[i]?time:tim[i], i+1);
			}
			if(!depth)
			{
				return;
			}
		}
	}
}

int recurs(int stat)
{
	if(used[stat])
	{
		return dp[stat];
	}
	used[stat] = 1;
	if(stat == 0)
	{
		return dp[stat]=0;
	}
	dp[stat] = 1000000000;
	dfs(stat, stat, 0, 0, 0, 0);
	return dp[stat];
}

int main()
{
	int i;
	while(scanf("%d%d", &m, &n) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &tim[i], &wei[i]);
		}
		memset(used, 0, sizeof(used));
		printf("%d\n", recurs((1<<n)-1));
	}
	return 0;
}
