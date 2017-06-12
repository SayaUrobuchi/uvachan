#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[10000];
int dp[10000];
int last[10000];
int times[10000];
int map[101][100], num[101];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

void backtracing(int now)
{
	if(last[now] != -1)
	{
		backtracing(last[now]);
	}
	printf(" %d", ary[now]);
}

int main()
{
	int cas, n, m, i, j, k, x, y, len, maxnum, tempi, ways;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == -1 && m == -1)
		{
			break;
		}
		len = 0;
		while(scanf("%d%d", &x, &y) == 2)
		{
			if(!x && !y)
			{
				break;
			}
			ary[len++] = (x-1) * m + y;
		}
		qsort(ary, len, sizeof(int), comp);
		memset(num, 0, sizeof(num));
		for(i=0, maxnum=1, tempi=0, ways=0; i<len; i++)
		{
			dp[i] = 1;
			last[i] = -1;
			times[i] = 1;
			if(maxnum == 1)
			{
				ways++;
			}
			y = (ary[i]-1) % m + 1;
			for(j=1; j<=y; j++)
			{
				for(k=0; k<num[j]; k++)
				{
					if(dp[map[j][k]] + 1 > dp[i])
					{
						dp[i] = dp[map[j][k]] + 1;
						last[i] = map[j][k];
						times[i] = times[map[j][k]];
						if(maxnum < dp[i])
						{
							maxnum = dp[i];
							tempi = i;
							ways = times[i];
						}
						else if(maxnum == dp[i])
						{
							ways += times[i];
						}
					}
					else if(dp[map[j][k]] + 1 == dp[i])
					{
						times[i] += times[map[j][k]];
						if(maxnum == dp[i])
						{
							ways += times[map[j][k]];
						}
					}
				}
			}
			map[y][num[y]++] = i;
		}
		printf("CASE#%d: %d %d", ++cas, maxnum, ways);
		backtracing(tempi);
		putchar('\n');
	}
	return 0;
}
