#include <iostream>
#include <cmath>

double dp[1024];

int main()
{
	long long n;
	int i;
	double t;
	while (scanf("%lld", &n) == 1)
	{
		if (n > 32)
		{
			n = 32;
		}
		dp[2] = 1;
		for (i=3; i<=n; i++)
		{
			dp[i] = (i-1) * (dp[i-1]+dp[i-2]);
		}
		for (i=2, t=1; i<=n; t*=i++);
		printf("%.10lf\n", 1-dp[n]*1.0/t);
	}
	return 0;
}
