/*
	ID: sa072682
	LANG: C
	TASK: maze1
*/
#include <stdio.h>
#include <string.h>

int qx[10000], qy[10000], s[10000], chk[101][40];
char map[250][100], con[101][40][4];
char way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

char valid(int n, int m, int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

void bfs(int n, int m, int x, int y)
{
	int i, j, k, tx, ty, step;
	qx[0] = x;
	qy[0] = y;
	s[0] = 1;
	chk[x][y] = 1;
	for(i=0, j=1; i<j; i++)
	{
		x = qx[i];
		y = qy[i];
		step = s[i] + 1;
		for(k=0; k<4; k++)
		{
			if(con[x][y][k])
			{
				tx = x + way[k][0];
				ty = y + way[k][1];
				if(valid(n, m, tx, ty) && step < chk[tx][ty])
				{
					qx[j] = tx;
					qy[j] = ty;
					s[j++] = step;
					chk[tx][ty] = step;
				}
			}
		}
	}
}

int main()
{
	int n, m, w, h, i, j, k, p, q, ans;
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	scanf("%d%d", &m, &n);
	w = m * 2 + 1;
	h = n * 2 + 1;
	ans = 2147483647;
	gets(map[0]);
	for(i=0; i<h; i++)
	{
		gets(map[i]);
	}
	for(i=1, p=0; i<h; i+=2, p++)
	{
		for(j=1, q=0; j<w; j+=2, q++)
		{
			for(k=0; k<4; k++)
			{
				con[p][q][k] = (map[i+way[k][0]][j+way[k][1]] == 32);
			}
			chk[p][q] = 2147483647;
		}
	}
	for(k=0; k<n; k++)
	{
		if(con[k][0][2])
		{
			bfs(n, m, k, 0);
		}
		if(con[k][m-1][0])
		{
			bfs(n, m, k, m-1);
		}
	}
	for(k=0; k<m; k++)
	{
		if(con[0][k][3])
		{
			bfs(n, m, 0, k);
		}
		if(con[n-1][k][1])
		{
			bfs(n, m, n-1, k);
		}
	}
	for(i=0, ans=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if(chk[i][j] > ans)
			{
				ans = chk[i][j];
			}
		}
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
