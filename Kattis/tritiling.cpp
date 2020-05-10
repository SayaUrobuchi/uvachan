#include <stdio.h>

int dp[64];

int main()
{
	int i, j, n;
	dp[0] = 1;
	dp[1] = 0;
	for (i=2; i<=30; i++)
	{
		dp[i] = dp[i-2] * 3;
		for (j=i-4; j>=0; j-=2)
		{
			dp[i] += (dp[j] << 1);
		}
	}
	while (scanf("%d", &n) == 1)
	{
		if (n == -1)
		{
			break;
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
