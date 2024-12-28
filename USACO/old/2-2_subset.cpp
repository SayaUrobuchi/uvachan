/*
	ID: sa072682
	LANG: C
	TASK: subset
*/
#include <stdio.h>

long long dp[800];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, i, j, sum;
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	scanf("%d", &n);
	dp[0] = 1;
	for(i=1, sum=0; i<=n; i++)
	{
		sum += i;
		for(j=min(sum, 800); j>=i; j--)
		{
			dp[j] += dp[j-i];
		}
	}
	if(sum % 2)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", dp[sum/2]/2);
	}
	scanf(" ");
	return 0;
}
