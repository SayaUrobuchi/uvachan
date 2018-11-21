#include <stdio.h>
#include <string.h>

int n, m, x, y, z, map[35][35], c[4], dis[35][35][4], used[35][35][4];
int walkx[4] = {0, 1, 0, -1}, walky[4] = {1, 0, -1, 0};

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

void go(int dx, int dy, int dir)
{
	x = dx + walkx[dir];
	y = dy + walky[dir];
}

int adj(int f)
{
	return f % 4;
}

void move(int dx, int dy, int face, int dir)
{
	if(dir < 4)
	{
		go(dx, dy, z=adj(face+dir));
	}
	else
	{
		x = dx;
		y = dy;
		z = face;
	}
}

int main()
{
	int i, j, k, t, p, q, r;
	while(scanf("%d%d", &m, &n) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		scanf("%d%d%d%d", &c[0], &c[1], &c[2], &c[3]);
		memset(dis, 2, sizeof(dis));
		memset(used, 0, sizeof(used));
		dis[0][0][0] = 0;
		for(; ; )
		{
			for(i=0, t=2147483647; i<n; i++)
			{
				for(j=0; j<m; j++)
				{
					for(k=0; k<4; k++)
					{
						if(used[i][j][k] == 0 && dis[i][j][k] < t)
						{
							t = dis[i][j][k];
							p = i;
							q = j;
							r = k;
						}
					}
				}
			}
			used[p][q][r] = 1;
			if(p == n-1 && q == m-1)
			{
				printf("%d\n", dis[p][q][r]);
				break;
			}
			move(p, q, r, map[p][q]);
			if(valid(x, y))
			{
				if(dis[x][y][z] > dis[p][q][r])
				{
					dis[x][y][z] = dis[p][q][r];
				}
			}
			for(i=0; i<4; i++)
			{
				move(p, q, r, i);
				if(valid(x, y))
				{
					if(dis[x][y][z] > dis[p][q][r] + c[i])
					{
						dis[x][y][z] = dis[p][q][r] + c[i];
					}
				}
			}
		}
	}
	return 0;
}
