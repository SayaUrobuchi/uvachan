#include <stdio.h>

int ary[15], dp[15], value[15][5000], map[51][51], tbl[51], ans;
char chk[15][5000], chk2[51];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int tsp(int last, int now, int k)
{
	int i;
	char c;
	if(chk[last][now])
	{
		return value[last][now];
	}
	if(!now)
	{
		ans = min(ans, map[ary[last]][0] + map[ary[last]][0] - tbl[ary[last]]);
		chk[last][0] = 1;
		return value[last][0] = map[ary[last]][0] - tbl[ary[last]];
	}
	chk[last][now] = 1;
	value[last][now] = 0;
	c = 1;
	for(i=0; i<k; i++)
	{
		if(now & dp[i])
		{
			if(c)
			{
				c = 0;
				value[last][now] = tsp(i, now-dp[i], k) + map[ary[i]][ary[last]] - tbl[ary[last]];
				ans = min(ans, value[last][now] + map[0][ary[last]]);
			}
			else
			{
				value[last][now] = min(value[last][now], tsp(i, now-dp[i], k) + map[ary[i]][ary[last]] - tbl[ary[last]]);
				ans = min(ans, value[last][now] + map[0][ary[last]]);
			}
		}
	}
	return value[last][now];
}

int main()
{
	int count, n, m, i, j, k;
	double temp;
	dp[0] = 1;
	for(i=1; i<13; i++)
	{
		dp[i] = dp[i-1] * 2;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<=n; i++)
		{
			for(j=0; j<=n; j++)
			{
				map[i][j] = -1;
			}
			tbl[i] = 0;
			chk2[i] = 1;
		}
		while(m--)
		{
			scanf("%d%d%lf", &i, &j, &temp);
			temp *= 100;
			temp += 0.1;
			if(map[i][j] == -1)
			{
				map[i][j] = map[j][i] = (int)temp;
			}
			else
			{
				if(map[i][j] > (int)temp)
				{
					map[i][j] = map[j][i] = (int)temp;
				}
			}
		}
		for(k=0; k<=n; k++)
		{
			for(i=0; i<=n; i++)
			{
				if(map[i][k] != -1)
				{
					for(j=0; j<=n; j++)
					{
						if(map[k][j] != -1 && (map[i][j] == -1 || map[i][k] + map[k][j] < map[i][j]))
						{
							map[i][j] = map[i][k] + map[k][j];
						}
					}
				}
			}
		}
		scanf("%d", &m);
		for(i=0, k=0; i<m; i++)
		{
			scanf("%d%lf", &j, &temp);
			temp *= 100;
			temp += 0.1;
			if(chk2[j])
			{
				ary[k++] = j;
				chk2[j] = 0;
			}
			tbl[j] += (int)temp;
		}
		for(i=0; i<dp[k]; i++)
		{
			for(j=0; j<k; j++)
			{
				chk[j][i] = 0;
			}
		}
		ans = 0;
		for(i=0; i<k; i++)
		{
			tsp(i, dp[k]-1-dp[i], k);
		}
		/*for(i=0; i<dp[k]; i++)
		{
			for(j=0; j<k; j++)
			{
				printf("%d %d %.2f %.2f\n", i, j, value[j][i], value[j][i]+map[0][ary[j]]);
			}
		}*/
		if(ans < 0)
		{
			printf("Daniel can save $%d.%02d\n", (-ans)/100, (-ans)%100);
		}
		else
		{
			printf("Don't leave the house\n");
		}
	}
	return 0;
}
