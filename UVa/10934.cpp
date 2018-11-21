#include <stdio.h>

int used[101][200][200];
int dp[101][200][200];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int recursion(int num, int left, int right)
{
	int i, temp;
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
		return dp[num][left][right]=right-left+1;
	}
	dp[num][left][right] = 2147483640;
	for(i=left; i<=right; i++)
	{
		if(max(recursion(num-1, left, i-1), recursion(num, i+1, right))+1 < dp[num][left][right])
		{
			dp[num][left][right] = max(recursion(num-1, left, i-1), recursion(num, i+1, right))+1;
			temp = i;
		}
	}
	/*if(num == 3)
		printf(" %d %d %d => %d\n", num, left, right, temp);*/
	return dp[num][left][right];
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) == 2)
	{
		printf("%d\n", recursion(n, 1, m));
	}
	return 0;
}
