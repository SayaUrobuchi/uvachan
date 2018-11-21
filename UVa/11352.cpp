#include <stdio.h>
#include <string.h>

int n, m;
int queuex[10201], queuey[10201];
int step[10201];
int kx[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int ky[8] = {2, -2, -2, 2, 1, -1, -1, 1};
int px[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int py[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int chk[101][101];
char map[101][101];

int validk(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m && map[x][y] == '.';
}

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m && map[x][y] != 'X' && !chk[x][y];
}

int main()
{
	int count, i, j, k, x, y, tx, ty, sx, sy, ex, ey, s;
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
				if(map[i][j] == 'Z')
				{
					map[i][j] = 'X';
					for(k=0; k<8; k++)
					{
						x = i + kx[k];
						y = j + ky[k];
						if(validk(x, y))
						{
							map[x][y] = 'X';
						}
					}
				}
				else if(map[i][j] == 'A')
				{
					sx = i;
					sy = j;
				}
				else if(map[i][j] == 'B')
				{
					ex = i;
					ey = j;
				}
			}
		}
		queuex[0] = sx;
		queuey[0] = sy;
		step[0] = 0;
		memset(chk, 0, sizeof(chk));
		chk[sx][sy] = 1;
		for(i=0, j=1; i<j; i++)
		{
			x = queuex[i];
			y = queuey[i];
			s = step[i] + 1;
			for(k=0; k<8; k++)
			{
				tx = x + px[k];
				ty = y + py[k];
				if(valid(tx, ty))
				{
					if(tx == ex && ty == ey)
					{
						break;
					}
					chk[tx][ty] = 1;
					queuex[j] = tx;
					queuey[j] = ty;
					step[j++] = s;
				}
			}
			if(k < 8)
			{
				break;
			}
		}
		if(i == j)
		{
			printf("King Peter, you can't go now!\n");
		}
		else
		{
			printf("Minimal possible length of a trip is %d\n", s);
		}
	}
	return 0;
}
