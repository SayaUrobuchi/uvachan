#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DPN 550
#define QN 1500000

int n, m, xn, yn, num;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int px1[505], px2[505], py1[505], py2[505], cost[505];
int map[DPN][DPN], inq[DPN][DPN], dis[DPN][DPN];
int qx[QN], qy[QN];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
	int i, j, k, x, y, d, sx, sy, ex, ey, nx, ny, pid;
	while(scanf("%d%d", &n, &m) == 2)
	{
		scanf("%d", &num);
		for(i=0, xn=0, yn=0; i<num; i++)
		{
			scanf("%d%d%d%d%d", &px1[i], &py1[i], &px2[i], &py2[i], &cost[i]);
		}
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		memset(map, -1, sizeof(map));
		for(i=0; i<num; i++)
		{
			map[px1[i]][py1[i]] = i;
		}
		memset(inq, 0, sizeof(inq));
		memset(dis, -1, sizeof(dis));
		inq[sx][sy] = 1;
		qx[0] = sx;
		qy[0] = sy;
		dis[sx][sy] = 0;
		for(i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			inq[x][y] = 0;
			if(~map[x][y])
			{
				pid = map[x][y];
				d = dis[x][y] + cost[pid];
				nx = px2[pid];
				ny = py2[pid];
				if(dis[nx][ny] == -1 || dis[nx][ny] > d)
				{
					dis[nx][ny] = d;
					if(!inq[nx][ny])
					{
						inq[nx][ny] = 1;
						qx[j] = nx;
						qy[j] = ny;
						j++;
					}
				}
			}
			else
			{
				for(k=0; k<4; k++)
				{
					nx = x + dx[k];
					ny = y + dy[k];
					if(valid(nx, ny))
					{
						d = dis[x][y] + 1;
						if(dis[nx][ny] == -1 || dis[nx][ny] > d)
						{
							dis[nx][ny] = d;
							if(!inq[nx][ny])
							{
								inq[nx][ny] = 1;
								qx[j] = nx;
								qy[j] = ny;
								j++;
							}
						}
					}
				}
			}
		}
		printf("%d\n", dis[ex][ey]);
	}
	return 0;
}
