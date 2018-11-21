#include <stdio.h>
#include <string.h>

int n;
int map[41][41];
int queuex[5000], queuey[5000];
int step[5000], type[5000];
int chk[41][41];
int regkx[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int regky[8] = {2, -2, -2, 2, 1, -1, -1, 1};
int bix[4] = {2, -2, 2, -2};
int biy[4] = {-2, 2, 2, -2};

int valid(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= n && !map[x][y];
}

int main()
{
	int i, j, k, s, t, x, y, tx, ty, ex, ey;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		n += n;
		scanf("%d%d%d%d", &x, &y, &ex, &ey);
		memset(map, 0, sizeof(map));
		while(scanf("%d%d", &i, &j) == 2)
		{
			if(!i && !j)
			{
				break;
			}
			map[i][j] = 1;
		}
		if(x == ex && y == ey)
		{
			printf("Result : 0\n");
			continue;
		}
		queuex[0] = x;
		queuey[0] = y;
		step[0] = 0;
		type[0] = 3;
		memset(chk, 0, sizeof(chk));
		chk[x][y] = 7;
		for(i=0, j=1; i<j; i++)
		{
			x = queuex[i];
			y = queuey[i];
			s = step[i] + 1;
			t = type[i];
			if(t)
			{
				for(k=0; k<8; k++)
				{
					tx = x + regkx[k];
					ty = y + regky[k];
					if(valid(tx, ty) && !(chk[tx][ty] & 1))
					{
						if(tx == ex && ty == ey)
						{
							break;
						}
						chk[tx][ty]++;
						queuex[j] = tx;
						queuey[j] = ty;
						step[j] = s;
						type[j++] = 0;
					}
				}
				if(k < 8)
				{
					break;
				}
			}
			if(t != 1)
			{
				for(k=0; k<4; k++)
				{
					tx = x + bix[k];
					ty = y + biy[k];
					if(valid(tx, ty) && !(chk[tx][ty] & 2))
					{
						if(tx == ex && ty == ey)
						{
							break;
						}
						chk[tx][ty] += 2;
						queuex[j] = tx;
						queuey[j] = ty;
						step[j] = s;
						type[j++] = 1;
					}
				}
				if(k < 4)
				{
					break;
				}
			}
			if(t != 2)
			{
				tx = x;
				ty = n - y + 1;
				if(valid(tx, ty) && !(chk[tx][ty] & 4))
				{
					if(tx == ex && ty == ey)
					{
						break;
					}
					chk[tx][ty] += 4;
					queuex[j] = tx;
					queuey[j] = ty;
					step[j] = s;
					type[j++] = 2;
				}
				tx = n - x + 1;
				ty = y;
				if(valid(tx, ty) && !(chk[tx][ty] & 4))
				{
					if(tx == ex && ty == ey)
					{
						break;
					}
					chk[tx][ty] += 4;
					queuex[j] = tx;
					queuey[j] = ty;
					step[j] = s;
					type[j++] = 2;
				}
			}
		}
		if(i == j)
		{
			printf("Solution doesn't exist\n");
		}
		else
		{
			printf("Result : %d\n", s);
		}
	}
	return 0;
}
