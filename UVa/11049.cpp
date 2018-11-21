#include <stdio.h>
#include <string.h>

int wx1[3], wx2[3], wy1[3], wy2[3];
int used[7][7];
int queuex[50], queuey[50];
int type[50];
int from[50];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {-1, 0, 1, 0};
char tbl[4] = {'N', 'E', 'S', 'W'};

int valid(int x, int y)
{
	return x > 0 && x <= 6 && y > 0 && y <= 6;
}

int validmove(int x, int y, int nx, int ny)
{
	int i;
	if(x == nx)
	{
		for(i=0; i<3; i++)
		{
			if(x > wx1[i] && x <= wx2[i])
			{
				if((y == wy1[i] && ny == wy1[i]+1) || (ny == wy1[i] && y == wy1[i]+1))
				{
					return 0;
				}
			}
		}
	}
	else
	{
		for(i=0; i<3; i++)
		{
			if(y > wy1[i] && y <= wy2[i])
			{
				if((x == wx1[i] && nx == wx1[i]+1) || (nx == wx1[i] && x == wx1[i]+1))
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

void backtracing(int now)
{
	if(from[now])
	{
		backtracing(from[now]);
	}
	printf("%c", tbl[type[now]]);
}

int main()
{
	int i, j, k, x, y, sx, sy, ex, ey, tx, ty;
	while(scanf("%d%d", &sx, &sy) == 2)
	{
		if(!sx && !sy)
		{
			break;
		}
		scanf("%d%d", &ex, &ey);
		for(i=0; i<3; i++)
		{
			scanf("%d%d%d%d", &wx1[i], &wy1[i], &wx2[i], &wy2[i]);
			if(wx1[i] > wx2[i])
			{
				k = wx1[i];
				wx1[i] = wx2[i];
				wx2[i] = k;
			}
			if(wy1[i] > wy2[i])
			{
				k = wy1[i];
				wy1[i] = wy2[i];
				wy2[i] = k;
			}
		}
		if(sx == ex && sy == ey)
		{
			printf("\n");
			continue;
		}
		queuex[0] = sx;
		queuey[0] = sy;
		memset(used, 0, sizeof(used));
		used[sx][sy] = 1;
		for(i=0, j=1; i<j; i++)
		{
			x = queuex[i];
			y = queuey[i];
			/*printf("%d %d\n", x, y);*/
			for(k=0; k<4; k++)
			{
				tx = x + wayx[k];
				ty = y + wayy[k];
				if(valid(tx, ty) && validmove(x, y, tx, ty) && !used[tx][ty])
				{
					used[tx][ty] = 1;
					queuex[j] = tx;
					queuey[j] = ty;
					type[j] = k;
					from[j++] = i;
					if(tx == ex && ty == ey)
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
		backtracing(j-1);
		printf("\n");
	}
	return 0;
} 
