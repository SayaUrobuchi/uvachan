#include <stdio.h>
#include <math.h>

double corx[30];
double y[30][4];
double dp[30][4];

double dis(double x, double y)
{
	return sqrt(x*x+y*y);
}

int main()
{
	int n, i, j, k, p, q;
	double temp;
	while(scanf("%d", &n) == 1)
	{
		if(n == -1)
		{
			break;
		}
		corx[0] = 0.0;
		y[0][0] = y[0][1] = y[0][2] = y[0][3] = 5.0;
		dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
		for(i=1; i<=n; i++)
		{
			scanf("%lf%lf%lf%lf%lf", &corx[i], &y[i][0], &y[i][1], &y[i][2], &y[i][3]);
			dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = 100000.0;
		}
		corx[++n] = 10.0;
		y[n][0] = y[n][1] = y[n][2] = y[n][3] = 5.0;
		dp[n][0] = dp[n][1] = dp[n][2] = dp[n][3] = 100000.0;
		for(i=0; i<n; i++)
		{
			for(p=0; p<4; p++)
			{
				for(j=i+1; j<=n; j++)
				{
					for(q=0; q<4; q++)
					{
						for(k=i+1; k<j; k++)
						{
							temp = y[i][p] + (y[j][q]-y[i][p]) * (corx[k]-corx[i]) / (corx[j]-corx[i]);
							if(temp < y[k][0] || (temp > y[k][1] && temp < y[k][2]) || temp > y[k][3])
							{
								break;
							}
						}
						if(k == j)
						{
							if(dp[i][p] + (temp=dis(y[i][p]-y[j][q], corx[i]-corx[j])) < dp[j][q])
							{
								dp[j][q] = dp[i][p] + temp;
							}
						}
					}
				}
			}
		}
		printf("%.2lf\n", dp[n][0]);
	}
	return 0;
}
