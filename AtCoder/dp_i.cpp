#include <iostream>
using namespace std;

double dp[4096][4096];

int main()
{
	int n, i, j;
	double ans, r;
	dp[0][0] = 1;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%lf", &r);
			dp[i][0] = dp[i-1][0] * (1-r);
			for (j=1; j<=i; j++)
			{
				dp[i][j] = dp[i-1][j-1] * r + dp[i-1][j] * (1-r);
			}
		}
		for (i=((n+1)>>1), ans=0; i<=n; i++)
		{
			ans += dp[n][i];
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
