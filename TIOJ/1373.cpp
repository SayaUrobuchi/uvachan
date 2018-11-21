#include <stdio.h>

int dir[10500], times[10500], qx[10500], qy[10500], n, m;
int dx[4]={0, 1, -1, 0}, dy[4]={1, 0, 0, -1};
char map[105][105];

int valid(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main()
{
	int i, j, k, x, y, t, d, f, sx, sy, tx, ty, ex, ey;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%s", map[i]+1);
		}
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		dir[0] = -100;
		times[0] = -1;
		qx[0] = sx;
		qy[0] = sy;
		map[sx][sy] = 0;
		for(i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			t = times[i];
			d = dir[i];
			for(k=0; k<4; k++)
			{
				if(k != d && k + d != 3)
				{
					for(f=0, tx=x+dx[k], ty=y+dy[k]; valid(tx, ty)&&map[tx][ty]!='X'; tx+=dx[k], ty+=dy[k])
					{
						if(map[tx][ty] == 'O')
						{
							map[tx][ty] = 0;
							qx[j] = tx;
							qy[j] = ty;
							times[j] = t+1;
							dir[j++] = k;
							if(tx == ex && ty == ey)
							{
								f = 1;
								break;
							}
						}
					}
					if(f)
					{
						break;
					}
				}
			}
			if(k < 4)
			{
				break;
			}
		}
		if(i == j)
		{
			printf("No Way!!\n");
		}
		else
		{
			printf("%d\n", t+1);
		}
	}
	return 0;
}
