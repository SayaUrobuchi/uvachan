#include <stdio.h>
#include <string.h>

int n, f;
int deg[205];
int used[205];
int map[205][205];

void dfs(int now)
{
	int i;
	f += deg[now] % 2;
	if(f)
	{
		return;
	}
	for(i=0; i<n; i++)
	{
		if(!used[i] && map[now][i])
		{
			used[i] = 1;
			dfs(i);
			if(f)
			{
				return;
			}
		}
	}
}

int main()
{
	int m, i, p, q;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(deg, 0, sizeof(deg));
		memset(map, 0, sizeof(map));
		while(m--)
		{
			scanf("%d%d", &p, &q);
			map[q][p] = map[p][q] = 1;
			deg[p]++;
			deg[q]++;
		}
		f = 0;
		memset(used, 0, sizeof(used));
		used[0] = 1;
		dfs(0);
		if(f)
		{
			printf("Not Possible\n");
		}
		else
		{
			for(i=0; i<n; i++)
			{
				if(!used[i])
				{
					break;
				}
			}
			if(i == n)
			{
				printf("Possible\n");
			}
			else
			{
				printf("Not Possible\n");
			}
		}
	}
	return 0;
}
