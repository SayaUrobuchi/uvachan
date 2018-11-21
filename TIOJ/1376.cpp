#include <stdio.h>
#include <string.h>

int used[30], link[30], num[30], map[30][30], n;

int match(int);

int set(int from, int now)
{
	used[n+now] = 1;
	if(link[now])
	{
		if(match(link[now]-1))
		{
			link[now] = from+1;
			return 1;
		}
		return 0;
	}
	else
	{
		link[now] = from+1;
		return 1;
	}
}

int match(int now)
{
	int i;
	used[now] = 1;
	for(i=0; i<num[now]; i++)
	{
		if(used[n+map[now][i]] == 0)
		{
			if(set(now, map[now][i]))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int m, i, j, c;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(num, 0, sizeof(num));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][num[i]++] = j;
		}
		memset(link, 0, sizeof(link));
		for(i=0, c=0; i<n; i++)
		{
			memset(used, 0, sizeof(used));
			c += match(i);
		}
		printf("%d\n", c);
	}
	return 0;
}
