/*
	ID: sa072682
	LANG: C
	TASK: game1
*/
#include <stdio.h>

int dp[101][101], dp2[101][101], chk[101][101], ary[101];

void recursion(int left, int right, int type)
{
	if(chk[left][right])
	{
		return;
	}
	chk[left][right] = 1;
	if(left > right)
	{
		return;
	}
	recursion(left+1, right, 1-type);
	recursion(left, right-1, 1-type);
	if(type)
	{
		if(dp[left+1][right] + ary[left] > dp[left][right-1] + ary[right])
		{
			dp[left][right] = dp[left+1][right] + ary[left];
			dp2[left][right] = dp2[left+1][right];
		}
		else
		{
			dp[left][right] = dp[left][right-1] + ary[right];
			dp2[left][right] = dp2[left][right-1];
		}
	}
	else
	{
		if(dp2[left+1][right] + ary[left] > dp2[left][right-1] + ary[right])
		{
			dp[left][right] = dp[left+1][right];
			dp2[left][right] = dp2[left+1][right] + ary[left];
		}
		else
		{
			dp[left][right] = dp[left][right-1];
			dp2[left][right] = dp2[left][right-1] + ary[right];
		}
	}
}

int main()
{
	int n, i;
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	recursion(0, n-1, 1);
	printf("%d %d\n", dp[0][n-1], dp2[0][n-1]);
	scanf(" ");
	return 0;
}
