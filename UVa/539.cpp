#include <stdio.h>
#include <string.h>

int n, ans, set;
int map[30][30], tbl[30], chk[30];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

void dfs(int now, int depth)
{
	int i;
	tbl[set] = max(tbl[set], depth);
	chk[now] = set;
	for(i=0; i<n; i++)
	{
		if(map[now][i])
		{
			map[now][i]--;
			map[i][now]--;
			dfs(i, depth+1);
			map[now][i]++;
			map[i][now]++;
		}
	}
}

int main()
{
	int m, i, j;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		memset(map, 0, sizeof(map));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][j]++;
			map[j][i]++;
		}
		memset(chk, 0, sizeof(chk));
		memset(tbl, 0, sizeof(tbl));
		for(i=0, ans=0, set=0; i<n; i++)
		{
			set += !chk[i];
			dfs(i, 0);
		}
		for(i=1; i<=set; i++)
		{
			ans += tbl[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
