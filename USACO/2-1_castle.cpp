/*
	ID: sa072682
	LANG: C
	TASK: castle
*/
#include <stdio.h>

int con[51][51], count[2501], map[51][51], queue[2501][2], dp[5];
int way[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}, ans;

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

void floodfill(int x, int y, int c)
{
	int i, j, k, tx, ty;
	queue[0][0] = x;
	queue[0][1] = y;
	for(i=0, j=1; i<j; i++)
	{
		x = queue[i][0];
		y = queue[i][1];
		for(k=0; k<4; k++)
		{
			if(!(con[x][y] & dp[k]))
			{
				tx = x + way[k][0];
				ty = y + way[k][1];
				if(!map[tx][ty])
				{
					map[tx][ty] = c;
					queue[j][0] = tx;
					queue[j++][1] = ty;
				}
			}
		}
	}
	count[c] = j;
	ans = max(ans, j);
}

int main()
{
	int n, m, i, j, c, x, y, type;
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	dp[0] = 1;
	for(i=1; i<5; i++)
	{
		dp[i] = dp[i-1] * 2;
	}
	scanf("%d%d", &m, &n);
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf("%d", &con[i][j]);
		}
	}
	for(i=0, c=1; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if(!map[i][j])
			{
				map[i][j] = c;
				floodfill(i, j, c);
				c++;
			}
		}
	}
	printf("%d\n%d\n", c-1, ans);
	/*for(i=1; i<c; i++)
	{
		printf("%d %d\n", i, count[i]);
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%3d", map[i][j]);
		}
		printf("\n");
	}*/
	for(j=0, ans=0; j<m; j++)
	{
		for(i=n-1; i>-1; i--)
		{
			if(i && map[i][j] != map[i-1][j])
			{
				if(count[map[i][j]] + count[map[i-1][j]] > ans)
				{
					ans = count[map[i][j]] + count[map[i-1][j]];
					type = 1;
					x = i + 1;
					y = j + 1;
				}
			}
			if(j + 1 < m && map[i][j] != map[i][j+1])
			{
				if(count[map[i][j]] + count[map[i][j+1]] > ans)
				{
					ans = count[map[i][j]] + count[map[i][j+1]];
					type = 0;
					x = i + 1;
					y = j + 1;
				}
			}
		}
	}
	if(type)
	{
		printf("%d\n%d %d N\n", ans, x, y);
	}
	else
	{
		printf("%d\n%d %d E\n", ans, x, y);
	}
	scanf(" ");
	return 0;
}
