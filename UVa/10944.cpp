#include <stdio.h>

int nut[15][2], time[17], map[17][17], dp[16][65536], queue[65536], max[65536];

int maxnum(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int dis(int x1, int y1, int x2, int y2)
{
	x1 -= x2;
	y1 -= y2;
	if(x1 < 0)
	{
		x1 = -x1;
	}
	if(y1 < 0)
	{
		y1 = -y1;
	}
	return maxnum(x1, y1);
}

int main()
{
	int n, m, i, j, k, l, p, q, sx, sy, now, maximum, num, temp, temp2;
	char buf[100];
	time[0] = 1;
	for(i=1; i<17; i++)
	{
		time[i] = time[i-1] * 2;
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		gets(buf);
		for(i=0, k=0; i<n; i++)
		{
			gets(buf);
			for(j=0; j<m; j++)
			{
				if(buf[j] == 'L')
				{
					sx = i;
					sy = j;
				}
				else if(buf[j] == '#')
				{
					nut[k][0] = i;
					nut[k][1] = j;
					for(l=0; l<k; l++)
					{
						map[k][l] = map[l][k] = dis(i, j, nut[l][0], nut[l][1]);
					}
					k++;
				}
			}
		}
		for(i=0; i<k; i++)
		{
			map[i][16] = dp[i][time[i]] = dis(nut[i][0], nut[i][1], sx, sy);
			queue[i] = time[i];
			max[i] = i;
		}
		for(i=0, j=k, num=k; i<j; i++)
		{
			now = queue[i];
			maximum = max[i] + 1;
			for(k=maximum; k<num; k++)
			{
				temp = time[k];
				queue[j] = temp2 = now + temp;
				max[j++] = k;
				for(p=0; p<num; p++)
				{
					if(p == k)
					{
						dp[p][temp2] = 1000000;
					}
					else
					{
						dp[p][temp2] = map[p][k] + dp[k][now];
					}
				}
				for(l=0; l<maximum; l++)
				{
					if((now | time[l]) == now)
					{
						temp = time[l];
						for(p=0; p<num; p++)
						{
							if(p != l && map[p][l] + dp[l][temp2-temp] < dp[p][temp2])
							{
								dp[p][temp2] = map[p][l] + dp[l][temp2-temp];
							}
						}
					}
				}
				for(p=0; p<num; p++)
				{
					printf("%d %d %d\n", p, temp2, dp[p][temp2]);
				}
			}
		}
		p=time[num]-1;
		dp[16][p] = map[0][16] + dp[0][p];
		printf("%d %d\n", map[0][16], dp[0][p]);
		for(i=1; i<num; i++)
		{
			printf("%d %d\n", map[i][16], dp[i][p]);
			if(map[i][16] + dp[i][p] < dp[16][p])
			{
				dp[16][p] = map[i][16] + dp[i][p];
				printf("XD %d %d\n", dp[16][p], map[i][16]);
			}
		}
		printf("%d\n", dp[16][p]);
	}
	return 0;
}
