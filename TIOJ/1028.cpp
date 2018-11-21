#include <stdio.h>
#include <string.h>

int n;
int used[10005][15], dp[10005][15], ff[10005][15], map[15][15], from[15][15];
int ary[15];

void calc(int t, int h)
{
	int i, tt, temp;
	if(used[t][h])
	{
		return;
	}
	used[t][h] = 1;
	if(t == 0)
	{
		dp[t][h] = 0;
		return;
	}
	dp[t][h] = 2147483647;
	for(i=0, temp=2147483647; i<n; i++)
	{
		if((t & (1<<i)) && map[h][i])
		{
			tt = t - (1<<i);
			calc(tt, i);
			if(dp[tt][i] + map[i][h] < dp[t][h])
			{
				dp[t][h] = dp[tt][i] + map[i][h];
				ff[t][h] = i;
				temp = from[i][h];
			}
			else if(dp[tt][i] + map[i][h] == dp[t][h])
			{
				if(temp > from[i][h])
				{
					temp = from[i][h];
					ff[t][h] = i;
				}
			}
		}
	}
}

void ppat(int p, int q)
{
	if(from[p][q] != -1)
	{
		ppat(p, from[p][q]);
		printf(" %d", from[p][q]);
		ppat(from[p][q], q);
	}
}

void trc(int t, int h)
{
	printf(" %d", h);
	if(t == 0)
	{
		return;
	}
	ppat(h, ff[t][h]);
	trc(t-(1<<ff[t][h]), ff[t][h]);
}

int main()
{
	int m, i, k, j, p, q, r, tar;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(map, 0, sizeof(map));
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			map[p][q] = map[q][p] = r;
			from[p][q] = from[q][p] = -1;
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				if(map[i][k])
				{
					for(j=0; j<n; j++)
					{
						if(map[k][j])
						{
							if(map[i][j] == 0 || map[i][k]+map[k][j]<map[i][j])
							{
								map[i][j] = map[i][k]+map[k][j];
								from[i][j] = k;
							}
						}
					}
				}
			}
		}
		scanf("%d", &k);
		for(i=0, tar=0; i<k; i++)
		{
			scanf("%d", &ary[i]);
			tar += (1<<ary[i]);
		}
		tar -= (1<<ary[0]);
		memset(used, 0, sizeof(used));
		calc(tar, ary[0]);
		printf("Minimum travel distance: %d\n", dp[tar][ary[0]]);
		printf("Travel route:");
		trc(tar, ary[0]);
		printf("\n");
	}
	return 0;
}
