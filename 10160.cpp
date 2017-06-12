#include <stdio.h>
#include <string.h>

int n, ans;
int num[40];
int map[40][40];
int used[40];

void dfs(int depth, int nodes)
{
	int i, c;
	if(nodes >= ans)
	{
		return;
	}
	if(depth > n)
	{
		for(i=1; i<=n; i++)
		{
			if(!used[i])
			{
				for(c=0; c<num[i]; c++)
				{
					if(used[map[i][c]])
					{
						break;
					}
				}
				if(c == num[i])
				{
					return;
				}
			}
		}
		ans = nodes;
		return;
	}
	for(i=0, c=0; i<num[depth]; i++)
	{
		c += used[map[depth][i]];
	}
	dfs(depth+1, nodes);
	if(!num[depth] || c != num[depth])
	{
		used[depth] = 1;
		dfs(depth+1, nodes+1);
		used[depth] = 0;
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
		memset(num, 0, sizeof(num));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][num[i]++] = j;
			map[j][num[j]++] = i;
		}
		ans = 1000000;
		memset(used, 0, sizeof(used));
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
