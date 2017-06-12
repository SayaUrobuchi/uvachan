#include <stdio.h>
#include <string.h>

int map[55][55], ptr[55], deg[55], used[55];

void dfs(int now)
{
	int target;
	for(; ptr[now]<=50; )
	{
		if(map[now][target=ptr[now]])
		{
			map[now][target]--;
			map[target][now]--;
			dfs(target);
			printf("%d %d\n", target, now);
		}
		else
		{
			ptr[now]++;
		}
	}
}

void testconn(int now)
{
	int i;
	for(i=1; i<=50; i++)
	{
		if(!used[i] && map[now][i])
		{
			used[i] = 1;
			testconn(i);
		}
	}
}

int main()
{
	int cas, count, m, i, j;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &m);
		memset(map, 0, sizeof(map));
		memset(ptr, 0, sizeof(ptr));
		memset(deg, 0, sizeof(deg));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][j]++;
			map[j][i]++;
			deg[i]++;
			deg[j]++;
		}
		printf("Case #%d\n", ++cas);
		for(i=1; i<=50; i++)
		{
			if(deg[i] % 2)
			{
				break;
			}
		}
		if(i <= 50)
		{
			printf("some beads may be lost\n");
		}
		else
		{
			memset(used, 0, sizeof(used));
			for(i=1; i<=50; i++)
			{
				if(deg[i])
				{
					used[i] = 1;
					testconn(i);
					for(j=1; j<=50; j++)
					{
						if(deg[j] && !used[j])
						{
							break;
						}
					}
					if(j <= 50)
					{
						printf("some beads may be lost\n");
					}
					else
					{
						dfs(i);
					}
					break;
				}
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
