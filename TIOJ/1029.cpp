#include <stdio.h>

int ary[1000], dp[1000][1000], dp2[1000][1000];
char chk[1000][1000];

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
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		recursion(0, i-1, 1);
		printf("%d %d\n", dp[0][i-1], dp2[0][i-1]);
	}
	return 0;
}
