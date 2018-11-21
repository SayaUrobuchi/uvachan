#include <stdio.h>
#include <string.h>

int used[250], link[120], old[120][120], oldhash[120][120], yng[120][120], ynghash[120][120];
int ans[120], n;

int find(int);

int match(int from, int now)
{
	used[n+now] = 1;
	if(link[now] == 0)
	{
		link[now] = from;
		return 1;
	}
	else
	{
		if(used[link[now]] == 0)
		{
			if(ynghash[from] < ynghash[link[now]])
			{
				if(find(link[now]))
				{
					link[now] = from;
					return 1;
				}
			}
		}
		return 0;
	}
}

int find(int now)
{
	int i, target;
	used[now] = 1;
	for(i=1; i<=n; i++)
	{
		target = old[now][i];
		if(used[n+target] == 0)
		{
			if(match(now, target))
			{
				ans[now] = target;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j;
	while(scanf("%d", &n) == 1)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf("%d", &old[i][j]);
				oldhash[i][old[i][j]] = j;
			}
		}
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf("%d", &yng[i][j]);
				ynghash[i][yng[i][j]] = j;
			}
		}
		memset(link, 0, sizeof(link));
		for(i=1; i<=n; i++)
		{
			memset(used, 0, sizeof(used));
			if(find(i) == 0)
			{
				break;
			}
		}
		if(i <= n)
		{
			printf("No Way!!\n");
		}
		else
		{
			for(i=1; i<=n; i++)
			{
				printf("#%d match to #%d\n", i, ans[i]);
			}
		}
	}
	return 0;
}
