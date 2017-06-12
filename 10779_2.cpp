#include <stdio.h>
#include <string.h>

int n, m;
int sused[26], tused[12];
int map[12][26];
int assigned[12][26];

int require(int);

int exchange(int now)
{
	int i;
	for(i=1; i<=m; i++)
	{
		if(!sused[i] && !map[now][i] && map[1][i] > 1)
		{
			map[1][i]--;
			map[now][i]++;
			assigned[now][i]++;
			return 1;
		}
	}
	for(i=1; i<=m; i++)
	{
		if(!sused[i] && !map[now][i] && map[1][i] == 1)
		{
			if(require(i))
			{
				map[1][i]--;
				map[now][i]++;
				assigned[now][i]++;
				return 1;
			}
		}
	}
	for(i=1; i<=m; i++)
	{
		if(!sused[i] && assigned[now][i] < 0 && map[1][i])
		{
			if(require(i))
			{
				map[1][i]--;
				map[now][i]++;
				assigned[now][i]++;
				return 1;
			}
		}
	}
	return 0;
}

int require(int now)
{
	int i;
	sused[now] = 1;
	for(i=2; i<=n; i++)
	{
		if(!tused[i] && map[i][now] > 1)
		{
			tused[i] = 1;
			if(exchange(i))
			{
				map[1][now]++;
				map[i][now]--;
				assigned[i][now]--;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int cas, count, i, j, c, o;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(map, 0, sizeof(map));
		memset(assigned, 0, sizeof(assigned));
		for(i=1; i<=n; i++)
		{
			scanf("%d", &o);
			while(o--)
			{
				scanf("%d", &j);
				map[i][j]++;
			}
		}
		for(i=1, c=0; i<=m; i++)
		{
			if(!map[1][i])
			{
				memset(sused, 0, sizeof(sused));
				memset(tused, 0, sizeof(tused));
				c += require(i);
			}
			else
			{
				c++;
			}
		}
		printf("Case #%d: %d\n", ++cas, c);
	}
	return 0;
}
