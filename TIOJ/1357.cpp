#include <stdio.h>

int dp[51];

int main()
{
	int count, n, i, j, k, l;
	for(i=1, j=0, k=1, l=1; i<=50; i++)
	{
		dp[i] = dp[i-1] + l;
		if(++j == k)
		{
			j = 0;
			k++;
			l <<= 1;
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
