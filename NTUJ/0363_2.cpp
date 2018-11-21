#include <stdio.h>
#include <string.h>

#define MAXN 10005

int s, e, c, bestt, bestd, h, map[105][305], dis[105][105], time[105][105], num[105], used[105], dd[105][MAXN];

void dfs(int now, int d, int t)
{
	int i, next;
	if(dd[now][d] <= t)
	{
		return;
	}
	for(i=0; i<d; i++)
	{
		if(dd[now][i] <= t)
		{
			return;
		}
	}
	dd[now][d] = t;
	if(now == e)
	{
		return;
	}
	for(i=0; i<num[now]; i++)
	{
		next = map[now][i];
		if(used[next] == 0)
		{
			used[next] = 1;
			dfs(next, d+dis[now][next], t+time[now][next]);
			used[next] = 0;
		}
	}
}

int main()
{
	int n, m, i, j, k, l, d, t, nn, next, last;
	while(scanf("%d%d", &n, &m) == 2)
	{
		scanf("%d%d", &s, &e);
		while(m--)
		{
			scanf("%d%d%d%d", &i, &j, &k, &l);
			map[i][num[i]++] = j;
			map[j][num[j]++] = i;
			dis[i][j] = dis[j][i] = k;
			time[i][j] = time[j][i] = l;
		}
		memset(dd, 1, sizeof(dd));
		memset(used, 0, sizeof(used));
		used[s] = 1;
		c = 0;
		dfs(s, 0, 0);
		for(i=0, last=MAXN, c=0; i<MAXN; i++)
		{
			if(dd[e][i] < last)
			{
				last = dd[e][i];
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
