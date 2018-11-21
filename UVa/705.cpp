#include <stdio.h>
#include <string.h>

int n, m, count, maxlength;
int visited[80][80][4];
int wayx[4] = {-1, 0, 1, 0};
int wayy[4] = {0, -1, 0, 1};
char map[80][80];

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int dfs(int x, int y, int dir, int depth)
{
	int target, tx, ty, temp;
	if(map[x][y] == '/')
	{
		if(!dir)
		{
			target = 1;
		}
		else if(dir == 1)
		{
			target = 0;
		}
		else if(dir == 2)
		{
			target = 3;
		}
		else
		{
			target = 2;
		}
	}
	else
	{
		if(!dir)
		{
			target = 3;
		}
		else if(dir == 1)
		{
			target = 2;
		}
		else if(dir == 2)
		{
			target = 1;
		}
		else
		{
			target = 0;
		}
	}
	visited[x][y][target] = 1;
	/*printf("%d %d %d %d\n", x, y, dir, target);*/
	if(valid(tx=x+wayx[target], ty=y+wayy[target]))
	{
		if(visited[tx][ty][temp=(target+2)%4])
		{
			/*intf("%d %d %d\n", tx, ty, temp);*/
			count++;
			maxlength = max(maxlength, depth);
			return 1;
		}
		visited[tx][ty][temp] = 1;
		dfs(tx, ty, temp, depth+1);
	}
	/*else
	{
		printf("Escaped!!\n");
	}*/
	return 0;
}

int main()
{
	int cas, i, j, k;
	cas = 0;
	while(scanf("%d%d", &m, &n) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		gets(map[0]);
		for(i=0; i<n; i++)
		{
			gets(map[i]);
		}
		memset(visited, 0, sizeof(visited));
		for(i=0; i<n; i++)
		{
			if(!visited[i][0][1])
			{
				visited[i][0][1] = 1;
				dfs(i, 0, 1, 1);
			}
			if(!visited[i][m-1][3])
			{
				visited[i][m-1][3] = 1;
				dfs(i, m-1, 3, 1);
			}
		}
		for(i=0; i<m; i++)
		{
			if(!visited[0][i][0])
			{
				visited[0][i][0] = 1;
				dfs(0, i, 0, 1);
			}
			if(!visited[n-1][i][2])
			{
				visited[n-1][i][2] = 1;
				dfs(n-1, i, 2, 1);
			}
		}
		for(i=0, count=0, maxlength=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				for(k=0; k<4; k++)
				{
					if(!visited[i][j][k])
					{
						visited[i][j][k] = 1;
						dfs(i, j, k, 1);
					}
				}
			}
		}
		if(count)
		{
			printf("Maze #%d:\n%d Cycles; the longest has length %d.\n\n", ++cas, count, maxlength);
		}
		else
		{
			printf("Maze #%d:\nThere are no cycles.\n\n", ++cas);
		}
	}
	return 0;
}
