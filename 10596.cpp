#include <stdio.h>
#include <string.h>

int n, f;
int deg[205];
int used[205];
int map[205][205];

void dfs(int now)
{
	int i;
	f += deg[now] & 1;
	if(f > 2)
	{
		return;
	}
	for(i=0; i<n; i++)
	{
		if(!used[i] && map[now][i])
		{
			used[i] = 1;
			dfs(i);
			if(f > 2)
			{
				return;
			}
		}
	}
}

int main()
{
	int m, i, p, q, r, s;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(deg, 0, sizeof(deg));
		memset(map, 0, sizeof(map));
		s = m;
		while(m--)
		{
			scanf("%d%d", &p, &q);
			map[q][p] = map[p][q] = 1;
			deg[p]++;
			deg[q]++;
		}
		f = 0;
		memset(used, 0, sizeof(used));
		r = 0;
		for(i=0; i<n; i++)
		{
			if(deg[i])
			{
				if (r && !used[i])
				{
					break;
				}
				if (used[i])
				{
					continue;
				}
				used[i] = 1;
				dfs(i);
				if (f)
				{
					break;
				}
				r = 1;
			}
		}
		if(i == n && s)
		{
			printf("Possible\n");
		}
		else
		{
			printf("Not Possible\n");
		}
	}
	return 0;
}
