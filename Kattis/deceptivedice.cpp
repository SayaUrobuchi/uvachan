#include <iostream>

double dp[1024];

int main()
{
	int n, m, i, j;
	double avg, sum;
	while (scanf("%d%d", &n, &m) == 2)
	{
		--m;
		for (i=1, avg=0; i<=n; i++)
		{
			dp[i] = i;
			avg += i;
		}
		for (i=1, avg/=n; i<=m; i++)
		{
			for (j=1, sum=0; j<=n; j++)
			{
				dp[j] = std::max(dp[j], avg);
				sum += dp[j];
			}
			avg = sum / n;
		}
		printf("%.10lf\n", avg);
	}
	return 0;
}
