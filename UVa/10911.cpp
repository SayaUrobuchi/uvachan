#include <stdio.h>
#include <math.h>

int ary[16][2], time[18], queue[65536], max[65536];
double dp[65536];

double dis(int x1, int y1, int x2, int y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
	int cas, n, n2, i, j, k, l, m, p, q, temp, temp2, now;
	char buf[100], chk;
	cas = 0;
	time[0] = 1;
	for(i=1; i<18; i++)
	{
		time[i] = time[i-1] * 2;
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		n2 = n * 2;
		for(i=0, k=0; i<n2; i++)
		{
			scanf("%s%d%d", buf, &ary[i][0], &ary[i][1]);
			for(j=0; j<i; j++)
			{
				queue[k] = time[i] + time[j];
				dp[queue[k]] = dis(ary[i][0], ary[i][1], ary[j][0], ary[j][1]);
				max[k++] = i;
			}
		}
		for(i=0, j=k; i<j; i++)
		{
			now = queue[i];
			for(k=m=max[i]+1; k<n2; k++)
			{
				for(l=k+1; l<n2; l++)
				{
					temp = time[k] + time[l];
					dp[temp+now] = dp[temp] + dp[now];
					queue[j] = (temp += now);
					max[j++] = l;
					for(p=1, chk=1; p<l; p++)
					{
						if((temp | time[p]) == temp)
						{
							for(q=0; q<p; q++)
							{
								if((temp | time[q]) == temp)
								{
									temp2 = time[p] + time[q];
									if(dp[temp2] + dp[temp-temp2] < dp[temp] || chk)
									{
										dp[temp] = dp[temp2] + dp[temp-temp2];
										chk = 0;
									}
								}
							}
						}
					}
				}
			}
		}
		printf("Case %d: %.2f\n", ++cas, dp[time[n2]-1]);
	}
	return 0;
}
