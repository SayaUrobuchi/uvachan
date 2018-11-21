#include <stdio.h>
#include <string.h>

int n, f;
int map[55][55], used[55][55][4];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int p, int q, int dir)
{
	if(p == 0 || q == 0 || p == n+1 || q == n+1)
	{
		if(f)
		{
			printf("%d %d\n", p, q);
			return -1;
		}
		f = 1;
	}
	if(used[p][q][dir])
	{
		printf("0 0\n");
		return -1;
	}
	used[p][q][dir] = 1;
	if(map[p][q])
	{
		dir = (dir+3) % 4;
	}
	return dfs(p+dx[dir], q+dy[dir], dir);
}

int main()
{
	int count, m, i, p, q, dir;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(map, 0, sizeof(map));
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			map[p][q] = 1;
		}
		scanf("%d%d", &p, &q);
		dir = 0;
		if(p == n+1)
		{
			dir = 2;
		}
		else if(q == n+1)
		{
			dir = 3;
		}
		else if(q == 0)
		{
			dir = 1;
		}
		memset(used, 0, sizeof(used));
		f = 0;
		dfs(p, q, dir);
	}
	return 0;
}
