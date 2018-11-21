#include <stdio.h>

int sqr[105], dp[10005];

int main()
{
	int count, i, j, n;
	for(i=1; i<=101; i++)
	{
		sqr[i] = i*i;
	}
	for(i=1; i<=10000; i++)
	{
		dp[i] = i;
		for(j=1; sqr[j]<=i; j++)
		{
			if(dp[i] > dp[i-sqr[j]]+1)
			{
				dp[i] = dp[i-sqr[j]] + 1;
			}
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}
