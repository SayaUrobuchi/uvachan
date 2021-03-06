#include <stdio.h>
#include <string.h>

int used[15][105][105];
int dp[155][105][105];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int recursion(int num, int left, int right)
{
	int i;
	if(left > right)
	{
		return 0;
	}
	if(used[num][left][right])
	{
		return dp[num][left][right];
	}
	used[num][left][right] = 1;
	if(num == 1)
	{
		return dp[num][left][right]=((right+left)*(right-left+1))/2;
	}
	dp[num][left][right] = 2147483640;
	for(i=left; i<=right; i++)
	{
		dp[num][left][right] = min(dp[num][left][right], max(recursion(num-1, left, i-1), recursion(num, i+1, right))+i);
	}
	return dp[num][left][right];
}

int main()
{
	int count, n, m;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		printf("%d\n", recursion(n, 1, m));
	}
	return 0;
}
