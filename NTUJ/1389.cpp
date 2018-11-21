#include <stdio.h>
#include <string.h>

#define N 100005
#define M 100005

int n, m, o;
int qx[N], qy[N], qz[N], qs[N], tbl[105][105][105], used[105][105][105], dp[M];
int val[105], dis[105];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char map[105][105][105];

int valid(int x, int y)
{
	return x>=0 && x<n && y>=0 && y<m;
}

int main()
{
	int count, pn, lim, i, j, k, x, y, z, s, tz, ty, tx, ts, sx, sy, sz, d;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d%d", &o, &n, &m, &pn, &lim);
		for(i=0; i<o; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%s", map[i][j]);
				for(k=0; k<m; k++)
				{
					if(map[i][j][k] == 'S')
					{
						sx = j;
						sy = k;
						sz = i;
					}
				}
			}
		}
		memset(tbl, 0, sizeof(tbl));
		for(i=1; i<=pn; i++)
		{
			scanf("%d%d%d%d", &z, &x, &y, &val[i]);
			tbl[z-1][x-1][y-1] = i;
			dis[i] = -1;
		}
		memset(used, 0, sizeof(used));
		used[sz][sx][sy] = 1;
		qx[0] = sx;
		qy[0] = sy;
		qz[0] = sz;
		qs[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			z = qz[i];
			s = qs[i];
			if(tbl[z][x][y])
			{
				dis[tbl[z][x][y]] = s;
			}
			for(k=0; k<4; k++)
			{
				tx = x + dx[k];
				ty = y + dy[k];
				tz = z;
				ts = s+1;
				if(valid(tx, ty) && map[tz][tx][ty] != 'X')
				{
					if(!used[tz][tx][ty])
					{
						used[tz][tx][ty] = 1;
						qx[j] = tx;
						qy[j] = ty;
						qz[j] = tz;
						qs[j] = ts;
						j++;
					}
				}
			}
			if(map[z][x][y] == 'U')
			{
				tx = x;
				ty = y;
				tz = z+1;
				ts = s+1;
				if(valid(tx, ty) && map[tz][tx][ty] != 'X')
				{
					if(!used[tz][tx][ty])
					{
						used[tz][tx][ty] = 1;
						qx[j] = tx;
						qy[j] = ty;
						qz[j] = tz;
						qs[j] = ts;
						j++;
					}
				}
			}
			else if(map[z][x][y] == 'D')
			{
				tx = x;
				ty = y;
				tz = z-1;
				ts = s+1;
				if(valid(tx, ty) && map[tz][tx][ty] != 'X')
				{
					if(!used[tz][tx][ty])
					{
						used[tz][tx][ty] = 1;
						qx[j] = tx;
						qy[j] = ty;
						qz[j] = tz;
						qs[j] = ts;
						j++;
					}
				}
			}
		}
		memset(dp, 0, sizeof(dp));
		for(i=1; i<=pn; i++)
		{
			if(dis[i] != -1)
			{
				d = dis[i]*3;
				for(j=lim; j>=d; j--)
				{
					if(dp[j] < dp[j-d]+val[i])
					{
						dp[j] = dp[j-d]+val[i];
					}
				}
			}
		}
		printf("%d\n", dp[lim]);
	}
	return 0;
}
