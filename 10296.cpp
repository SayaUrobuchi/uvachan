#include <stdio.h>
#include <string.h>

int map[15][15], path[15], min;
char list[15], check[15], lnum;

void dfs(int now, int depth)
{
	int i, j;
	if(depth == lnum)
	{
		if(now < min || min == -1)
		{
			min = now;
		}
		return;
	}
	for(i=0; i<lnum; i++)
	{
		if(check[i])
		{
			check[i] = 0;
			break;
		}
	}
	for(j=i+1; j<lnum; j++)
	{
		if(check[j])
		{
			check[j] = 0;
			dfs(now + map[list[i]][list[j]], depth + 2);
			check[j] = 1;
		}
	}
	check[i] = 1;
}

int main()
{
	int n, m, i, j, k, ans;
	memset(check, 1, sizeof(check));
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		scanf("%d", &m);
		memset(map, 0, sizeof(map));
		memset(path, 0, sizeof(path));
		ans = 0;
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			ans += k;
			path[--i]++;
			path[--j]++;
			if(k < map[i][j] || !map[i][j])
			{
				map[i][j] = k;
				map[j][i] = k;
			}
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				if(map[i][k])
				{
					for(j=0; j<n; j++)
					{
						if(map[k][j])
						{
							if(map[i][k] + map[k][j] < map[i][j] || !map[i][j])
							{
								map[i][j] = map[i][k] + map[k][j];
							}
						}
					}
				}
			}
		}
		lnum = 0;
		for(i=0; i<n; i++)
		{
			if(path[i] % 2)
			{
				list[lnum++] = i;
			}
		}
		min = -1;
		dfs(0, 0);
		printf("%d\n", ans + min);
	}
	return 0;
} 