#include <stdio.h>
#include <string.h>

int n, m, o;
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
int coorx[3000], coory[3000];
int used[55][55];
int map[55][55];
int mark[55][55];
int conn[55][55][4];
int queuex[3000], queuey[3000];
int from[3000];
int dir[3000];

int mod(int now)
{
	if(now >= 4)
	{
		return now - 4;
	}
	return now;
}

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

void backtracing(int now)
{
	int u, v, ux, uy, vx, vy;
	if(now)
	{
		u = from[now];
		v = now;
		backtracing(u);
		ux = queuex[u];
		uy = queuey[u];
		vx = queuex[v];
		vy = queuey[v];
		mark[ux][uy] = 1;
		mark[vx][vy] = 1;
		if(conn[ux][uy][dir[v]] && conn[vx][vy][mod(dir[v]+2)])
		{
			conn[ux][uy][dir[v]] = 0;
		}
		else
		{
			conn[ux][uy][dir[v]] = conn[vx][vy][mod(dir[v]+2)] = 1;
		}
	}
}

int main()
{
	int count, i, j, k, l, x, y, tx, ty;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		/*for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				map[i][j] = 0;
				mark[i][j] = 0;
				for(k=0; k<4; k++)
				{
					conn[i][j][k] = 1;
				}
			}
		}*/
		memset(map, 0, sizeof(map));
		memset(mark, 0, sizeof(mark));
		memset(conn, 1, sizeof(conn));
		for(i=0; i<o; i++)
		{
			scanf("%d%d", &coorx[i], &coory[i]);
			coorx[i]--;
			coory[i]--;
			map[coorx[i]][coory[i]] = 1;
		}
		for(l=0; l<o; l++)
		{
			memset(used, 0, sizeof(used));
			queuex[0] = coorx[l];
			queuey[0] = coory[l];
			used[coorx[l]][coory[l]] = 1;
			for(i=0, j=1; i<j; i++)
			{
				x = queuex[i];
				y = queuey[i];
				if(mark[x][y])
				{
					for(k=0; k<4; k++)
					{
						if(conn[x][y][k])
						{
							tx = x + wayx[k];
							ty = y + wayy[k];
							if(valid(tx, ty))
							{
								if(!conn[tx][ty][mod(k+2)])
								{
									if(!used[tx][ty])
									{
										used[tx][ty] = 1;
										queuex[j] = tx;
										queuey[j] = ty;
										dir[j] = k;
										from[j++] = i;
									}
									conn[x][y][k] = 0;
									break;
								}
							}
						}
					}
				}
				else
				{
					for(k=0; k<4; k++)
					{
						if(conn[x][y][k])
						{
							tx = x + wayx[k];
							ty = y + wayy[k];
							if(!valid(tx, ty))
							{
								conn[x][y][k] = 0;
								break;
							}
							if(!map[tx][ty] && !used[tx][ty])
							{
								used[tx][ty] = 1;
								queuex[j] = tx;
								queuey[j] = ty;
								dir[j] = k;
								from[j++] = i;
							}
						}
					}
					if(k < 4)
					{
						break;
					}
				}
			}
			if(i == j)
			{
				break;
			}
			backtracing(i);
		}
		if(l < o)
		{
			printf("not possible\n");
		}
		else
		{
			printf("possible\n");
		}
	}
	return 0;
}
