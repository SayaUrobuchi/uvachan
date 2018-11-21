#include <stdio.h>

int dp[305];

int main()
{
	int cas, count, n, i;
	cas = 0;
	for(i=1; i<=300; i++)
	{
		dp[i] = dp[i-1] + i * ((i+1)*(i+2)/2);
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%d %d %d\n", ++cas, n, dp[n]);
	}
	return 0;
}
