#include <stdio.h>

int dp[100005];

int main()
{
	int i, j, n, m;
	dp[1] = 1;
	for(i=2, j=2; i<=100000; i++)
	{
		dp[i] = dp[i-1];
		if(j*j == i)
		{
			dp[i]++;
			j++;
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		printf("%d\n", dp[m]-dp[n-1]);
	}
	return 0;
}

