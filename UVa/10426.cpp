#include <stdio.h>
#include <string.h>

int n, m;
int map[4][17][17], mon[4][17][17];
int chk[17][17];
int queuex[300], queuey[300];
int step[300];
int aryx[4], aryy[4];
int wayx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int wayy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
char str[10000];

int valid(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}

int main()
{
	int i, j, k, p, q, monsterx, monstery, x, y, tx, ty, s, ms, ans, temp;
	while(scanf("%s", str) == 1)
	{
		scanf("%d%d", &n, &m);
		memset(map, 0, sizeof(map));
		memset(mon, 0, sizeof(mon));
		for(i=0; i<4; i++)
		{
			scanf("%d%d", &aryx[i], &aryy[i]);
		}
		scanf("%d%d", &monsterx, &monstery);
		printf("%s\n", str);
		for(i=0; i<4; i++)
		{
			queuex[0] = aryx[i];
			queuey[0] = aryy[i];
			step[0] = 1;
			memset(chk, 0, sizeof(chk));
			chk[queuex[0]][queuey[0]] = 1;
			map[i][queuex[0]][queuey[0]] = 1;
			for(p=0, q=1, ms=-1; p<q; p++)
			{
				x = queuex[p];
				y = queuey[p];
				s = step[p] + 1;
				for(k=0; k<8; k++)
				{
					tx = x + wayx[k];
					ty = y + wayy[k];
					if(valid(tx, ty))
					{
						if(!chk[tx][ty])
						{
							chk[tx][ty] = 1;
							if(tx == monsterx && ty == monstery)
							{
								ms = s;
							}
							else
							{
								queuex[q] = tx;
								queuey[q] = ty;
								step[q++] = s;
								map[i][tx][ty] = s;
							}
						}
					}
				}
			}
			if(ms != -1)
			{
				queuex[0] = monsterx;
				queuey[0] = monstery;
				step[0] = ms;
				memset(chk, 0, sizeof(chk));
				chk[queuex[0]][queuey[0]] = 1;
				mon[i][queuex[0]][queuey[0]] = ms;
				for(p=0, q=1; p<q; p++)
				{
					x = queuex[p];
					y = queuey[p];
					s = step[p] + 1;
					for(k=0; k<8; k++)
					{
						tx = x + wayx[k];
						ty = y + wayy[k];
						if(valid(tx, ty))
						{
							if(!chk[tx][ty])
							{
								chk[tx][ty] = 1;
								if(tx == monsterx && ty == monstery)
								{
									ms = s;
								}
								else
								{
									queuex[q] = tx;
									queuey[q] = ty;
									step[q++] = s;
									mon[i][tx][ty] = s;
								}
							}
						}
					}
				}
			}
		}
		for(i=1, ans=2147483647; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				for(k=0, temp=0; k<4; k++)
				{
					if(!map[k][i][j])
					{
						break;
					}
					temp += map[k][i][j];
				}
				if(k == 4 && temp < ans)
				{
					ans = temp;
				}
				for(p=0; p<4; p++)
				{
					for(q=0, temp=0; q<4; q++)
					{
						if(p == q)
						{
							if(!mon[q][i][j])
							{
								break;
							}
							temp += mon[q][i][j];
						}
						else
						{
							if(!map[q][i][j])
							{
								break;
							}
							temp += map[q][i][j];
						}
					}
					if(q == 4 && temp < ans)
					{
						ans = temp;
					}
				}
			}
		}
		if(ans == 2147483647)
		{
			printf("Meeting is impossible.\n");
		}
		else
		{
			printf("Minimum time required is %d minutes.\n", ans-4);
		}
	}
	return 0;
}
