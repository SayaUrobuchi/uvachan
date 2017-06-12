#include <stdio.h>

double dp[50001], ans[50001];

int main()
{
	int count, n, i, temp;
	dp[1] = 0.125;
	ans[1] = 0.0;
	ans[2] = 0.5;
	for(i=2; i<50000; i++)
	{
		ans[i+1] = ans[i] + dp[i-1];
		dp[i] = (dp[i-1] * (4 * i - 2)) / ((i+1)*4);
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%.4f\n", ans[n/2]);
	}
	return 0;
}
