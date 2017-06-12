#include <stdio.h>

int final[30001], times[30001];
int dp[30001];

int f(int n)
{
	int temp;
	if(dp[n])
	{
		return dp[n];
	}
	if(n == 1)
	{
		return dp[n]=1;
	}
	temp = f(n-1) + 2;
	if(temp > n)
	{
		temp -= n;
	}
	return dp[n]=temp;
}

int recursion(int n)
{
	int temp;
	if(final[n])
	{
		return final[n];
	}
	temp = f(n);
	if(temp == n)
	{
		final[n] = n;
	}
	else
	{
		final[n] = recursion(temp);
		times[n] = times[temp] + 1;
	}
	return final[n];
}

int main()
{
	int cas, count, n;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		recursion(n);
		printf("Case %d: %d %d\n", ++cas, times[n], final[n]);
	}
	return 0;
}
