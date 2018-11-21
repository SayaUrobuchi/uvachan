#include <stdio.h>
#include <string.h>

int queuex[200], queuey[200], step[200], fire[9][16];
char map[10][18] = {"*****************",
					"*...*.......**..*",
					"**..*....*.*.*..*",
					"*......*.**.**.**",
					"*..**...**..**.**",
					"**.....**..*.*..*",
					"*....*..........*",
					"*.....****.*...**",
					"****.*.*........*",
					"*****************",
					};
char chk[9][16], wayx[4] = {0, 0, 1, -1}, wayy[4] = {1, -1, 0, 0};

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int valid(int x, int y)
{
	return x > -1 && x < 10 && y > -1 && y < 18;
}

int dis(int x1, int y1, int x2, int y2)
{
	return ab(x1-x2) + ab(y1-y2);
}

int main()
{
	int i, j, k, x, y, s, t, sx, sy, fx, fy, ex, ey, tx, ty;
	while(scanf("%d%d", &fx, &fy) == 2)
	{
		memset(chk, 1, sizeof(chk));
		memset(fire, 0, sizeof(fire));
		scanf("%d%d%d%d%d", &t, &sx, &sy, &ex, &ey);
		fire[ex][ey] = 2147483647;
		queuex[0] = fx;
		queuey[0] = fy;
		fire[fx][fy] = 1;
		step[0] = 1;
		for(i=0, j=1; i<j; i++)
		{
			x = queuex[i];
			y = queuey[i];
			s = step[i] + 1;
			for(k=0; k<4; k++)
			{
				tx = x + wayx[k];
				ty = y + wayy[k];
				if(valid(tx, ty) && map[tx][ty] == '.' && !fire[tx][ty])
				{
					queuex[j] = tx;
					queuey[j] = ty;
					step[j++] = fire[tx][ty] = s;
				}
			}
		}
		queuex[0] = sx;
		queuey[0] = sy;
		step[0] = t;
		for(i=0, j=1; i<j; i++)
		{
			x = queuex[i];
			y = queuey[i];
			s = step[i] + 1;
			if(fire[x][y] >= s)
			{
				for(k=0; k<4; k++)
				{
					tx = x + wayx[k];
					ty = y + wayy[k];
					if(valid(tx, ty) && map[tx][ty] == '.' && chk[tx][ty] && fire[tx][ty] > s)
					{
						if(tx == ex && ty == ey)
						{
							printf("%d\n", s-t);
							break;
						}
						queuex[j] = tx;
						queuey[j] = ty;
						step[j++] = s;
						chk[tx][ty] = 0;
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
			printf("Help!\n");
		}
	}
	return 0;
}
