#include <stdio.h>
#include <string.h>

int n, m, len;
char map[1000][1000];
int dis[1000][1000];
short tblx[10][450000], tbly[10][450000];
int num[10];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

int main()
{
	int count, i, j, k, c, v, x, y, tx, ty, lim;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &v);
				map[i][j] = v;
				dis[i][j] = 0;
			}
		}
		if(n == 1 && m == 1)
		{
			printf("%d\n", map[0][0]);
		}
		else
		{
			dis[0][0] = map[0][0] + 1;
			i = dis[0][0] % 10;
			memset(num, 0, sizeof(num));
			tblx[i][num[i]] = 0;
			tbly[i][num[i]++] = 0;
			for(; ; i++)
			{
				if(i == 10)
				{
					i = 0;
				}
				for(j=0; j<num[i]; j++)
				{
					x = tblx[i][j];
					y = tbly[i][j];
					for(k=0; k<4; k++)
					{
						tx = x + wayx[k];
						ty = y + wayy[k];
						if(valid(tx, ty) && !dis[tx][ty])
						{
							dis[tx][ty] = dis[x][y] + map[tx][ty];
							if(tx == n-1 && ty == m-1)
							{
								break;
							}
							v = dis[tx][ty] % 10;
							tblx[v][num[v]] = tx;
							tbly[v][num[v]++] = ty;
						}
					}
					if(k < 4)
					{
						break;
					}
				}
				if(j < num[i])
				{
					break;
				}
				num[i] = 0;
			}
			printf("%d\n", dis[tx][ty]-1);
		}
	}
	return 0;
}
