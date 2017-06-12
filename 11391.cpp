#include <stdio.h>
#include <string.h>

int n, m, lim;
int dirx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int diry[8] = {1, -1, 1, 0, -1, 1, 0, -1};
int queue[65536];
int c[65536];
int board[4][4];
int map[4][4];
int dp[4][4][65536];

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

void trans(int now)
{
	int i, j, k;
	for(i=0, k=1; i<n; i++)
	{
		for(j=0; j<m; j++, k<<=1)
		{
			board[i][j] = (now & k);
		}
	}
}

void floodfill(int x, int y)
{
	int i, tx, ty;
	map[x][y] = 1;
	lim++;
	for(i=0; i<8; i++)
	{
		tx = x + dirx[i];
		ty = y + diry[i];
		if(valid(tx, ty) && board[tx][ty] && !map[tx][ty])
		{
			floodfill(tx, ty);
		}
	}
}

int main()
{
	int cas, count, o, i, j, k, l, now, x, y, bx, by, dx, dy, temp, ans, flag;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		queue[0] = 0;
		flag = 0;
		memset(board, 0, sizeof(board));
		for(k=0; k<o; k++)
		{
			scanf("%d%d", &i, &j);
			i--;
			j--;
			if(queue[0] & 1<<(i*n+j))
			{
				flag = 1;
			}
			queue[0] |= 1<<(i*n+j);
			board[i][j] = 1;
		}
		if(flag)
		{
			printf("Case %d: %d\n", ++cas, 0);
		}
		else
		{
			if(dp[n-1][m-1][queue[0]])
			{
				printf("Case %d: %d\n", ++cas, dp[n-1][m-1][queue[0]]-1);
			}
			else
			{
				lim = 0;
				memset(map, 0, sizeof(map));
				floodfill(i, j);
				if(lim != o)
				{
					printf("Case %d: %d\n", ++cas, 0);
					dp[n-1][m-1][queue[0]] = 1;
				}
				else
				{
					memset(c, 0, sizeof(c));
					c[queue[0]] = 1;
					for(i=0, j=1, lim=(n-1)*n+m; i<j; i++)
					{
						now = queue[i];
						trans(now);
						for(x=0; x<n; x++)
						{
							for(y=0; y<m; y++)
							{
								if(board[x][y])
								{
									for(l=0; l<8; l++)
									{
										bx = x + dirx[l];
										by = y + diry[l];
										dx = bx + dirx[l];
										dy = by + diry[l];
										if(valid(dx, dy) && board[bx][by] && !board[dx][dy])
										{
											temp = now - (1<<(x*n+y)) - (1<<(bx*n+by)) + (1<<(dx*n+dy));
											if(c[temp])
											{
												c[temp] += c[now];
											}
											else
											{
												c[temp] = 1;
												queue[j++] = temp;
											}
										}
									}
								}
							}
						}
					}
					for(i=0, ans=0; i<lim; i++)
					{
						ans += c[1<<i];
					}
					printf("Case %d: %d\n", ++cas, ans);
					dp[n-1][m-1][queue[0]] = ans + 1;
				}
			}
		}
	}
	return 0;
}
