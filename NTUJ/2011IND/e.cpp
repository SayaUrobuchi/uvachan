#include <stdio.h>
#include <string.h>

int n, m;
int dx[]={0, 1, 0, -1}, dy[]={1, 0, -1, 0};
int vis[150][150][5], qx[1500000], qy[1500000], qs[1500000], qd[1500000];
char map[500][500];

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
	int count, i, j, k, l, c, x, y, d, s, tx, ty, td, ttx, tty;
	int sx, sy, sd, ex, ey, ed;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == 'S' || map[i][j] == 'E')
				{
					for(k=0, c=0; k<4; k++)
					{
						tx = i+dx[k];
						ty = j+dy[k];
						if(valid(tx, ty) && map[tx][ty]==map[i][j])
						{
							c++;
						}
						else
						{
							td = k;
						}
					}
					if(c == 3)
					{
						if(map[i][j] == 'S')
						{
							sx = i;
							sy = j;
							sd = td;
						}
						else
						{
							ex = i;
							ey = j;
							ed = td;
						}
					}
				}
			}
		}
		qx[0] = sx;
		qy[0] = sy;
		qd[0] = sd;
		qs[0] = 0;
		memset(vis, 0, sizeof(vis));
		vis[sx][sy][sd] = 1;
		for(i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			d = qd[i];
			s = qs[i];
			if(x == ex && y == ey && d == ed)
			{
				break;
			}
			for(k=0; k<4; k++)
			{
				tx = x + dx[k];
				ty = y + dy[k];
				td = d;
				if(valid(tx, ty) && map[tx][ty] != '#')
				{
					for(l=0; l<4; l++)
					{
						if(l != td)
						{
							ttx = tx + dx[l];
							tty = ty + dy[l];
							if(!valid(ttx, tty) || map[ttx][tty] == '#')
							{
								break;
							}
						}
					}
					if(l >= 4)
					{
						if(vis[tx][ty][td] == 0)
						{
							vis[tx][ty][td] = 1;
							qx[j] = tx;
							qy[j] = ty;
							qd[j] = td;
							qs[j] = s+1;
							j++;
						}
					}
				}
			}
			tx = x;
			ty = y;
			td = (d+1)%4;
			for(l=0; l<4; l++)
			{
				if(l != td)
				{
					ttx = tx + dx[l];
					tty = ty + dy[l];
					if(!valid(ttx, tty) || map[ttx][tty] == '#')
					{
						break;
					}
				}
			}
			if(l >= 4)
			{
				if(vis[tx][ty][td] == 0)
				{
					vis[tx][ty][td] = 1;
					qx[j] = tx;
					qy[j] = ty;
					qd[j] = td;
					qs[j] = s+1;
					j++;
				}
			}
			tx = x;
			ty = y;
			td = (d+3)%4;
			for(l=0; l<4; l++)
			{
				if(l != td)
				{
					ttx = tx + dx[l];
					tty = ty + dy[l];
					if(!valid(ttx, tty) || map[ttx][tty] == '#')
					{
						break;
					}
				}
			}
			if(l >= 4)
			{
				if(vis[tx][ty][td] == 0)
				{
					vis[tx][ty][td] = 1;
					qx[j] = tx;
					qy[j] = ty;
					qd[j] = td;
					qs[j] = s+1;
					j++;
				}
			}
		}
		if(i >= j)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", s);
		}
	}
	return 0;
}
