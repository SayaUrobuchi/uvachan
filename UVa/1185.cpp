#include <stdio.h>
#include <math.h>

const int N = 10000007;

double dp[N];

int main()
{
	int count, n, i;
	dp[0] = 1;
	for (i=1; i<N; i++)
	{
		dp[i] = dp[i-1] + log10(i);
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		printf("%.0lf\n", floor(dp[n]));
	}
	return 0;
}
