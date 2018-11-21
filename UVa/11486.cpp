#include <stdio.h>
#include <string.h>

int lnum, list[128];
int map[128][128], mnum[128];
long long tbl[32][128][128], dp[32][128];

void dfs2(int stat, int depth, int sel)
{
	if(sel == 4)
	{
		list[lnum++] = stat;
		return;
	}
	if(depth == 7)
	{
		return;
	}
	dfs2(stat+(1<<depth), depth+1, sel+1);
	dfs2(stat, depth+1, sel);
}

void dfs(int stat, int depth, int val)
{
	if(depth == 7)
	{
		map[stat][mnum[stat]++] = val;
		tbl[0][stat][val] = 1;
		return;
	}
	if(stat & (1<<depth))
	{
		if(depth > 0 && (val & (1<<(depth-1))) == 0)
		{
			dfs(stat, depth+1, val+(1<<(depth-1)));
		}
		if(depth < 6 && (val & (1<<(depth+1))) == 0)
		{
			dfs(stat, depth+1, val+(1<<(depth+1)));
		}
	}
	else
	{
		dfs(stat, depth+1, val);
	}
}

int main()
{
	int count, n, i, j, k, l, t, st, nx, tar;
	long long ans;
	dfs2(0, 0, 0);
	for(i=0; i<lnum; i++)
	{
		dfs(list[i], 0, 0);
	}
	for(j=1; j<=30; j++)
	{
		for(i=0; i<lnum; i++)
		{
			for(k=0; k<lnum; k++)
			{
				nx = list[k];
				for(l=0; l<lnum; l++)
				{
					tar = list[l];
					tbl[j][list[i]][tar] += tbl[j-1][list[i]][nx] * tbl[j-1][nx][tar];
					tbl[j][list[i]][tar] %= 1000000007;
				}
			}
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		n--;
		for(i=0, st=0; i<7; i++)
		{
			scanf("%d", &t);
			if(t)
			{
				st += (1<<i);
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[0][st] = 1;
		for(i=0; n; i++)
		{
			if(n & (1<<i))
			{
				n -= (1<<i);
				for(j=0; j<lnum; j++)
				{
					for(k=0; k<lnum; k++)
					{
						nx = list[k];
						dp[i+1][nx] += dp[i][list[j]] * tbl[i][list[j]][nx];
						dp[i+1][nx] %= 1000000007;
					}
				}
			}
			else
			{
				memcpy(dp[i+1], dp[i], sizeof(dp[0]));
			}
		}
		for(j=0, ans=0; j<lnum; j++)
		{
			ans += dp[i][list[j]];
			ans %= 1000000007;
		}
		printf("%d\n", (int)ans);
	}
	return 0;
}
