#include <stdio.h>
#include <string.h>

int queuex[100000], queuey[100000], step[100000], map[305][305], used[305][305];
int walkx[4] = {0, 1, 0, -1};
int walky[4] = {1, 0, -1, 0};

int valid(int x, int y, int s)
{
	return x >= 0 && x <= 302 && y >= 0 && y <= 302 && used[x][y] == 0 && map[x][y] > s;
}

int min(int p, int q)
{
	return p<q ? p : q;
}

int main()
{
	int n, i, j, k, x, y, tx, ty, p, q, t, s;
	while(scanf("%d", &n) == 1)
	{
		memset(map, 1, sizeof(map));
		memset(used, 0, sizeof(used));
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &p, &q, &t);
			map[p][q] = min(map[p][q], t);
			for(j=0; j<4; j++)
			{
				x = p + walkx[j];
				y = q + walky[j];
				if(valid(x, y, t))
				{
					map[x][y] = t;
				}
			}
		}
		if(map[0][0] == 0)
		{
			i = j = 0;
		}
		else
		{
			queuex[0] = queuey[0] = 0;
			step[0] = 0;
			used[0][0] = 1;
			for(i=0, j=1; i<j; i++)
			{
				x = queuex[i];
				y = queuey[i];
				s = step[i];
				if(map[x][y] >= 2000)
				{
					break;
				}
				for(k=0; k<4; k++)
				{
					tx = x + walkx[k];
					ty = y + walky[k];
					if(valid(tx, ty, s+1))
					{
						used[tx][ty] = 1;
						queuex[j] = tx;
						queuey[j] = ty;
						step[j++] = s + 1;
					}
				}
			}
		}
		if(i == j)
		{
			printf("%d\n", -1);
		}
		else
		{
			printf("%d\n", s);
		}
	}
	return 0;
}
