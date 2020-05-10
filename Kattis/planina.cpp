#include <stdio.h>

int dp[32];

int main()
{
	int n, i, j, k;
	dp[0] = 4;
	for (i=1, j=1, k=1; i<=15; i++, j<<=2, k<<=1)
	{
		dp[i] = dp[i-1] + j*5 - k*(k-1)*2;
	}
	while (scanf("%d", &n) == 1)
	{
		printf("%d\n", dp[n]);
	}
	return 0;
}
