#include <stdio.h>
#include <string.h>

#define INF 2147483647

int n, m, t;
int used[55][55], mark[55][55];
int queuex[2600], queuey[2600], step[2600];
int dp[10][1024], dused[10][1024];
int sdis[12], dis[12][12];
int wayx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int wayy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int px[12], py[12];
char map[55][55];

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && !used[x][y];
}

int recursion(int num, int tail, int state)
{
	int i;
	if(dused[tail][state])
	{
		return dp[tail][state];
	}
	dused[tail][state] = 1;
	if(num == 1)
	{
		return dp[tail][state]=sdis[tail];
	}
	dp[tail][state] = INF;
	for(i=0; i<t; i++)
	{
		if(i != tail && (state & (1<<i)))
		{
			if(recursion(num-1, i, state-(1<<tail)) + dis[i][tail] < dp[tail][state])
			{
				dp[tail][state] = dp[i][state-(1<<tail)] + dis[i][tail];
			}
		}
	}
	return dp[tail][state];
}

int main()
{
	int i, j, k, l, s, c, x, y, sx, sy, tx, ty, min;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		gets(map[0]);
		for(i=0; i<n; i++)
		{
			gets(map[i]);
		}
		memset(used, 0, sizeof(used));
		for(i=0, t=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '@')
				{
					sx = i;
					sy = j;
				}
				else if(map[i][j] == '~')
				{
					map[i][j] = '#';
				}
				else if(map[i][j] == '*')
				{
					map[i][j] = '#';
					for(k=0; k<8; k++)
					{
						tx = i + wayx[k];
						ty = j + wayy[k];
						if(valid(tx, ty) && map[tx][ty] != '*')
						{
							if(map[tx][ty] == '!' || map[tx][ty] == '@')
							{
								break;
							}
							map[tx][ty] = '#';
						}
					}
					if(k < 8)
					{
						break;
					}
				}
				else if(map[i][j] == '!')
				{
					mark[i][j] = t;
					px[t] = i;
					py[t] = j;
					t++;
				}
			}
			if(j < m)
			{
				break;
			}
		}
		if(i < n)
		{
			printf("-1\n");
		}
		else
		{
			queuex[0] = sx;
			queuey[0] = sy;
			step[0] = 0;
			used[sx][sy] = 1;
			for(i=0, j=1, c=0; i<j; i++)
			{
				x = queuex[i];
				y = queuey[i];
				s = step[i] + 1;
				for(k=0; k<4; k++)
				{
					tx = x + wayx[k];
					ty = y + wayy[k];
					if(valid(tx, ty) && map[tx][ty] != '#')
					{
						used[tx][ty] = 1;
						queuex[j] = tx;
						queuey[j] = ty;
						step[j] = s;
						j++;
						if(map[tx][ty] == '!')
						{
							sdis[mark[tx][ty]] = s;
							c++;
						}
					}
				}
			}
			/*for(i=0; i<n; i++)
			{
				printf("%s\n", map[i]);
			}
			printf("%d\n", c);*/
			if(t == 0)
			{
				printf("0\n");
			}
			else if(c < t)
			{
				printf("-1\n");
			}
			else
			{
				for(l=0; l<t; l++)
				{
					queuex[0] = px[l];
					queuey[0] = py[l];
					step[0] = 0;
					memset(used, 0, sizeof(used));
					used[px[l]][py[l]] = 1;
					for(i=0, j=1; i<j; i++)
					{
						x = queuex[i];
						y = queuey[i];
						s = step[i] + 1;
						for(k=0; k<4; k++)
						{
							tx = x + wayx[k];
							ty = y + wayy[k];
							if(valid(tx, ty) && map[tx][ty] != '#')
							{
								used[tx][ty] = 1;
								queuex[j] = tx;
								queuey[j] = ty;
								step[j] = s;
								j++;
								if(map[tx][ty] == '!')
								{
									dis[l][mark[tx][ty]] = s;
								}
							}
						}
					}
				}
				memset(dused, 0, sizeof(dused));
				for(i=0, min=INF; i<t; i++)
				{
					if(recursion(t, i, (1<<t)-1) + sdis[i] < min)
					{
						min = dp[i][(1<<t)-1] + sdis[i];
					}
				}
				printf("%d\n", min);
			}
		}
	}
	return 0;
}
