#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DPN 2050
#define QN 1500000

int n, m, xn, yn, num;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int px1[505], px2[505], py1[505], py2[505], cost[505];
int xlist[DPN], ylist[DPN], map[DPN][DPN], inq[DPN][DPN], dis[DPN][DPN];
int qx[QN], qy[QN];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int ab(int t)
{
	return t<0 ? -t : t;
}

int search(int tar, int *list, int len)
{
	int p, q, c;
	for(p=0, q=len-1; p<=q; )
	{
		c = ((p+q)>>1);
		if(list[c] == tar)
		{
			return c;
		}
		else if(list[c] > tar)
		{
			q = c-1;
		}
		else
		{
			p = c+1;
		}
	}
	return -1;
}

int valid(int x, int y)
{
	return x >= 0 && x < xn && y >= 0 && y < yn;
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
			xlist[xn++] = px1[i]-1;
			xlist[xn++] = px1[i];
			xlist[xn++] = px1[i]+1;
			ylist[yn++] = py1[i]-1;
			ylist[yn++] = py1[i];
			ylist[yn++] = py1[i]+1;
			xlist[xn++] = px2[i];
			ylist[yn++] = py2[i];
		}
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		xlist[xn++] = sx;
		ylist[yn++] = sy;
		xlist[xn++] = ex;
		ylist[yn++] = ey;
		qsort(xlist, xn, sizeof(int), comp);
		qsort(ylist, yn, sizeof(int), comp);
		for(i=0, j=0; j<xn; j++)
		{
			if(xlist[j] >= 0 && xlist[j] < n && (!i || xlist[j] != xlist[i-1]))
			{
				xlist[i++] = xlist[j];
			}
		}
		xn = i;
		for(i=0, j=0; j<yn; j++)
		{
			if(ylist[j] >= 0 && ylist[j] < n && (!i || ylist[j] != ylist[i-1]))
			{
				ylist[i++] = ylist[j];
			}
		}
		yn = i;
		memset(map, -1, sizeof(map));
		for(i=0; i<num; i++)
		{
			px1[i] = search(px1[i], xlist, xn);
			px2[i] = search(px2[i], xlist, xn);
			py1[i] = search(py1[i], ylist, yn);
			py2[i] = search(py2[i], ylist, yn);
			map[px1[i]][py1[i]] = i;
		}
		sx = search(sx, xlist, xn);
		sy = search(sy, ylist, yn);
		ex = search(ex, xlist, xn);
		ey = search(ey, ylist, yn);
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
						d = dis[x][y] + ab(xlist[nx]-xlist[x]) + ab(ylist[ny]-ylist[y]);
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
