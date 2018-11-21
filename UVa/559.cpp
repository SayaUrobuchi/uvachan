#include <stdio.h>
#include <string.h>

int map[1005][1005];
int dp[1005][1005];
int queuex[3000];
int queuey[3000];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int count, n, m, o, r, c, s, i, j, x, y, sx, sy, num;
	scanf("%d", &count);
	while(count--)
	{
		memset(map, 0, sizeof(map));
		scanf("%d%d%d", &n, &m, &o);
		while(o--)
		{
			scanf("%d%d", &sx, &sy);
			for(i=0; ; i++)
			{
				if(sx+i > n || sy+i > m)
				{
					break;
				}
				num = 0;
				for(x=sx+i, y=sy; y<sy+i; y++)
				{
					if(map[x][y])
					{
						break;
					}
					queuex[num] = x;
					queuey[num++] = y;
				}
				if(y < sy+i)
				{
					break;
				}
				for(; x>=sx; x--)
				{
					if(map[x][y])
					{
						break;
					}
					queuex[num] = x;
					queuey[num++] = y;
				}
				if(x >= sx)
				{
					break;
				}
				for(j=0; j<num; j++)
				{
					map[queuex[j]][queuey[j]] = 1;
				}
			}
		}
		for(i=n, s=-1; i>0; i--)
		{
			for(j=m; j>0; j--)
			{
				if(!map[i][j])
				{
					if(i < n && j < m)
					{
						dp[i][j] = min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]))+1;
					}
					else
					{
						dp[i][j] = 1;
					}
					if(dp[i][j] >= s)
					{
						s = dp[i][j];
						r = i;
						c = j;
					}
				}
				else
				{
					dp[i][j] = 0;
				}
			}
			/*for(j=1; j<=m; j++)
			{
				printf("%2d", map[i][j]);
			}
			printf("\n");*/
		}
		if(s == -1)
		{
			printf("game over\n");
		}
		else
		{
			printf("%d %d %d\n", r, c, s);
		}
	}
	return 0;
}
