#include <stdio.h>

#define INF 1e30

double dp[60];
double dist[60];
double price[60];

int main()
{
	int cas, n, i, j, k;
	double dest, cap, unit, fcost;
	cas = 0;
	while(scanf("%lf", &dest) == 1)
	{
		if(dest < 0)
		{
			break;
		}
		scanf("%lf%lf%lf%d", &cap, &unit, &fcost, &n);
		unit = 1.0 / unit;
		dp[0] = fcost * 100.0;
		for(i=1; i<=n+1; i++)
		{
			dp[i] = INF;
		}
		dist[0] = 0.0;
		for(i=1; i<=n; i++)
		{
			scanf("%lf%lf", &dist[i], &price[i]);
		}
		dist[++n] = dest;
		for(i=0; i<n; i++)
		{
			for(j=i+1; j<=n; j++)
			{
				/*printf("%d to %d: %.2lf %.2lf\n", i, j, cap, (dist[j]-dist[i])*unit);*/
				if((dist[j] - dist[i]) * unit <= cap)
				{
					if(j == n)
					{
						if(dp[j] > dp[i])
						{
							dp[j] = dp[i];
						}
					}
					else if((dist[j] - dist[i]) * unit >= cap / 200.0)
					{
						if(dp[j] > dp[i] + (dist[j]-dist[i]) * unit * price[j] + 200.0)
						{
							dp[j] = dp[i] + (dist[j]-dist[i]) * unit * price[j] + 200.0;
						}
					}
				}
				for(k=i+1; k<j; k++)
				{
					if((dist[k]-dist[i]) * unit <= cap)
					{
						if((dist[j]-dist[i]) * unit > cap && (dist[j]-dist[k]) * unit <= cap)
						{
							/*printf("%d => %d => %d\n", i, k, j);*/
							if(j == n)
							{
								/*printf("%.2lf %.2lf %.2lf\n", dp[j], dp[i], (dist[k]-dist[i]) * unit * price[k] + 200.0);*/
								if(dp[j] > dp[i] + (dist[k]-dist[i]) * unit * price[k] + 200.0)
								{
									dp[j] = dp[i] + (dist[k]-dist[i]) * unit * price[k] + 200.0;
								}
							}
							else
							{
								/*printf("%.2lf %.2lf\n", dp[j], dp[i] + (dist[k]-dist[i]) * unit * price[k] + (dist[j]-dist[k]) * unit * price[j] + 400.0);*/
								if(dp[j] > dp[i] + (dist[k]-dist[i]) * unit * price[k] + (dist[j]-dist[k]) * unit * price[j] + 400.0)
								{
									dp[j] = dp[i] + (dist[k]-dist[i]) * unit * price[k] + (dist[j]-dist[k]) * unit * price[j] + 400.0;
								}
							}
						}
					}
				}
			}
		}
		/*for(i=0; i<=n; i++)
		{
			printf("%d: %.2lf\n", i, dp[i]/100.0);
		}*/
		printf("Data Set #%d\n", ++cas);
		printf("minimum cost = $%.2lf\n", dp[n]/100.0);
	}
	return 0;
}
