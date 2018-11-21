#include <stdio.h>
#include <string.h>

int px[35], py[35], dis[15][15], qn[15][15];
int qx[1000000], qy[1000000], qs[1000000];
int dx[]={0, 1, 0, -1}, dy[]={1, 0, -1, 0};
char map[15][15];

int main()
{
	int cas, n, i, j, k, x, y, d, tx, ty, dd, lnum, last;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, lnum=0; i<n; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<n; j++)
			{
				if(map[i][j] >= 'A' && map[i][j] <= 'Z')
				{
					lnum++;
					px[map[i][j]-'A'] = i;
					py[map[i][j]-'A'] = j;
				}
			}
		}
		last = 1;
		for(k=1, dd=0; k<lnum; k++)
		{
			qx[0] = px[k-1];
			qy[0] = py[k-1];
			qs[0] = 0;
			qn[qx[0]][qy[0]] = last;
			memset(dis, 1, sizeof(dis));
			dis[qx[0]][qy[0]] = 0;
			for(i=0, j=1; i<j; i++)
			{
				x = qx[i];
				y = qy[i];
				if(x == px[k] && y == py[k])
				{
					break;
				}
				for(d=0; d<4; d++)
				{
					tx = x + dx[d];
					ty = y + dy[d];
					if(tx >= 0 && tx < n && ty >= 0 && ty < n)
					{
						if(map[tx][ty] == '.' || (map[tx][ty] >= 'A' && map[tx][ty] <= 'A'+k))
						{
							if(qs[i]+1 < dis[tx][ty])
							{
								dis[tx][ty] = qs[i]+1;
								qn[tx][ty] = qn[x][y];
								qx[j] = tx;
								qy[j] = ty;
								qs[j] = dis[tx][ty];
								j++;
							}
							else if(qs[i]+1 == dis[tx][ty])
							{
								qn[tx][ty] += qn[x][y];
								if(qn[tx][ty] >= 20437)
								{
									qn[tx][ty] %= 20437;
								}
							}
						}
					}
				}
			}
			if(i == j)
			{
				dd = -1;
				break;
			}
			dd += qs[i];
			last = qn[x][y];
		}
		if(dd == -1)
		{
			printf("Case %d: Impossible\n", ++cas);
		}
		else
		{
			printf("Case %d: %d %d\n", ++cas, dd, last);
		}
	}
	return 0;
}
