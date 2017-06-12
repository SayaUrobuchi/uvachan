#include <stdio.h>

int dp[51];

int main()
{
	int count, n;
	for(n=2; n<52; n++)
	{
		dp[n-1] = n * n / 2 - 1;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}