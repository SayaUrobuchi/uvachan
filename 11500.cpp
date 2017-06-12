#include <stdio.h>
#include <string.h>

int e1, e2, at;
int used[6][22][22];
double dp[6][22][22];

double calc(int p, int q, int r)
{
	if(used[r][p][q])
	{
		return dp[r][p][q];
	}
	used[r][p][q] = 1;
	if(p <= 0)
	{
		return dp[r][p][q] = 0.0;
	}
	else if(q <= 0)
	{
		return dp[r][p][q] = 100.0;
	}
	return dp[r][p][q] = (6-r)/6.0*calc(p-1, q+1, r)+r/6.0*calc(p+1, q-1, r);
}

int main()
{
	int d, i, j, k;
	for(i=1; i<=5; i++)
	{
		for(j=0; j<1000; j++)
		{
			memset(used[i], 0, sizeof(used[i]));
			for(k=2; k<=20; k++)
			{
				calc(1, k-1, i); 
			}
		}
	}
	while(scanf("%d%d%d%d", &e1, &e2, &at, &d) == 4)
	{
		if(e1 == 0 && e2 == 0 && at == 0 && d == 0)
		{
			break;
		}
		e1 = (e1-1) / d + 1;
		e2 = (e2-1) / d + 1;
		printf("%.1lf\n", dp[at][e1][e2]);
	}
	return 0;
}
