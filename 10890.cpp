#include <stdio.h>
#include <string.h>

char chk[30], map[32][31];
int treasure[30][2], s, t, ans;

int dis(int x1, int y1, int x2, int y2)
{
	x1 -= x2;
	y1 -= y2;
	if(x1 < 0)
	{
		x1 = -x1;
	}
	if(y1 < 0)
	{
		y1 = -y1;
	}
	return x1 + y1;
}

char con(int from, int to)
{
	int i;
	for(i=0; i<t; i++)
	{
		if(chk[i] && i != from && i != to && map[from][i] + map[i][to] == map[from][to])
		{
			return 0;
		}
	}
	return 1;
}

void dfs(int now, int depth, int value)
{
	int i;
	if(value >= ans)
	{
		return;
	}
	if(depth == s)
	{
		value += map[now][30];
		if(ans > value)
		{
			ans = value;
		}
		return;
	}
	for(i=0; i<t; i++)
	{
		if(chk[i] && con(now, i))
		{
			chk[i] = 0;
			dfs(i, depth+1, value+map[now][i]);
			chk[i] = 1;
		}
	}
}

int main()
{
	int cas, n, i, j, k;
	cas = 0;
	while(scanf("%d%d%d", &n, &t, &s) == 3)
	{
		if(!(n + t + s))
		{
			break;
		}
		memset(chk, 1, sizeof(chk));
		for(i=0; i<t; i++)
		{
			scanf("%d%d", &treasure[i][0], &treasure[i][1]);
			for(j=0; j<i; j++)
			{
				map[i][j] = map[j][i] = dis(treasure[i][0], treasure[i][1], treasure[j][0], treasure[j][1]);
			}
			map[i][30] = dis(treasure[i][0], treasure[i][1], n-1, n-1);
			map[31][i] = dis(treasure[i][0], treasure[i][1], 0, 0);
		}
		map[31][30] = dis(0, 0, n-1, n-1);
		ans = 2147483647;
		dfs(31, 0, 0);
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
