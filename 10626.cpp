#include <stdio.h>

int dp[1200000];
int used[1200000];

int getstate(int n, int v5, int v10)
{
	return n + v5*151 + v10*22801;
}

int recursion(int n, int v5, int v10)
{
	int s, v1;
	if(used[s=getstate(n, v5, v10)])
	{
		return dp[s];
	}
	used[s] = 1;
	if(!n)
	{
		return dp[s]=0;
	}
	dp[s] = 1000000000;
	v1 = (n<<3) - v5*5 - v10*10;
	if(v10)
	{
		if(recursion(n-1, v5, v10-1) + 1 < dp[s])
		{
			dp[s] = recursion(n-1, v5, v10-1) + 1;
		}
	}
	if(v10 && v1 > 2)
	{
		if(recursion(n-1, v5+1, v10-1) + 4 < dp[s])
		{
			dp[s] = recursion(n-1, v5+1, v10-1) + 4;
		}
	}
	if(v5 > 1)
	{
		if(recursion(n-1, v5-2, v10) + 2 < dp[s])
		{
			dp[s] = recursion(n-1, v5-2, v10) + 2;
		}
	}
	if(v5 > 0)
	{
		if(recursion(n-1, v5-1, v10) + 4 < dp[s])
		{
			dp[s] = recursion(n-1, v5-1, v10) + 4;
		}
	}
	if((n<<3) < dp[s])
	{
		dp[s] = (n<<3);
	}
	return dp[s];
}

int main()
{
	int count, n, v5, v10;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%*d%d%d", &n, &v5, &v10);
		printf("%d\n", recursion(n, v5, v10));
	}
	return 0;
}
