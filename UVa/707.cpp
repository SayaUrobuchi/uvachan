#include <stdio.h>
#include <string.h>

int w, h;
int num[101];
int l[101][101], t[101][101], r[101][101], b[101][101];
int dp[101][101][101];
int tbl[101];
int wayx[5] = {0, 0, 1, 0, -1};
int wayy[5] = {0, 1, 0, -1, 0};
int depth[10201];
int queuex[10201];
int queuey[10201];
int chk[101][101];
char result[101][101];

int valid(int x, int y)
{
	return x > 0 && x <= h && y > 0 && y <= w;
}

int main()
{
	int cas, m, i, j, k, p, x, y, tx, ty, d, sum, time, left, top, right, bottom, temp;
	cas = 0;
	while(scanf("%d%d%d", &w, &h, &time) == 3)
	{
		if(!w && !h && !time)
		{
			break;
		}
		scanf("%d", &m);
		memset(num, 0, sizeof(num));
		while(m--)
		{
			scanf("%d%d%d%d%d", &temp, &left, &top, &right, &bottom);
			l[temp][num[temp]] = left;
			t[temp][num[temp]] = top;
			r[temp][num[temp]] = right;
			b[temp][num[temp]++] = bottom;
		}
		memset(dp, 0, sizeof(dp));
		for(i=1, sum=0, temp=0; i<=h; i++)
		{
			for(j=1; j<=w; j++)
			{
				for(p=0; p<num[1]; p++)
				{
					if(i >= t[1][p] && i <= b[1][p] && j >= l[1][p] && j <= r[1][p])
					{
						break;
					}
				}
				if(p == num[1])
				{
					dp[1][i][j] = 1;
					tx = i;
					ty = j;
					sum++;
				}
			}
		}
		if(sum == 1)
		{
			temp = 1;
			depth[0] = 1;
			queuex[0] = tx;
			queuey[0] = ty;
		}
		k = 1;
		if(sum)
		{
			memset(tbl, 0, sizeof(tbl));
			for(k=2, sum=0; k<=time; k++)
			{
				for(i=1; i<=h; i++)
				{
					for(j=1; j<=w; j++)
					{
						for(p=0; p<num[k]; p++)
						{
							if(i >= t[k][p] && i <= b[k][p] && j >= l[k][p] && j <= r[k][p])
							{
								break;
							}
						}
						if(p == num[k])
						{
							for(p=0; p<5; p++)
							{
								x = i + wayx[p];
								y = j + wayy[p];
								if(valid(x, y))
								{
									dp[k][i][j] += dp[k-1][x][y];
								}
							}
							if(dp[k][i][j])
							{
								tx = i;
								ty = j;
								sum++;
							}
						}
					}
				}
				if(!sum)
				{
					break;
				}
				if(sum == 1)
				{
					temp = 1;
					depth[0] = k;
					queuex[0] = tx;
					queuey[0] = ty;
				}
				sum = 0;
			}
		}
		printf("Robbery #%d:\n", ++cas);
		if(k <= time)
		{
			printf("The robber has escaped.\n\n");
		}
		else
		{
			if(!temp)
			{
				printf("Nothing known.\n\n");
			}
			else
			{
				memset(chk, 0, sizeof(chk));
				chk[queuex[0]][queuey[0]] = depth[0];
				tbl[depth[0]] = 1;
				for(i=0, j=1, k=0; i<j; i++)
				{
					x = queuex[i];
					y = queuey[i];
					d = depth[i] - 1;
					if(tbl[d+1] == 1)
					{
						sprintf(result[k++], "Time step %d: The robber has been at %d,%d.\n", d+1, y, x);
						tbl[d+1] = 0;
					}
					if(!d)
					{
						break;
					}
					for(p=0; p<5; p++)
					{
						tx = x + wayx[p];
						ty = y + wayy[p];
						if(valid(tx, ty) && dp[d][tx][ty])
						{
							if(chk[tx][ty] != d)
							{
								chk[tx][ty] = d;
								queuex[j] = tx;
								queuey[j] = ty;
								depth[j++] = d;
								tbl[d]++;
							}
						}
					}
				}
				for(i=k-1; i>-1; i--)
				{
					printf("%s", result[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
