#include <stdio.h>
#include <string.h>

int map[30][30], n, ans;

void dfs(int now, int nod)
{
	int i, j, f, list[30];
	if(nod >= ans)
	{
		return;
	}
	if(now == n)
	{
		ans = nod;
		return;
	}
	for(i=0, j=0, f=0; i<n; i++)
	{
		if(map[now][i])
		{
			if(i <= now)
			{
				f = 1;
			}
			list[j++] = i;
			map[now][i] = map[i][now] = 0;
		}
	}
	dfs(now+1, nod+1);
	for(i=0; i<j; i++)
	{
		map[now][list[i]] = map[list[i]][now] = 1;
	}
	if(f == 0)
	{
		dfs(now+1, nod);
	}
}

int main()
{
	int m, i, j;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(map, 0, sizeof(map));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][j] = map[j][i] = 1;
		}
		ans = 2147483647;
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
