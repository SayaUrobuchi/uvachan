#include <stdio.h>

int dp[31];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

void recursion(int left, int right, int height)
{
	int center;
	if(left > right)
	{
		return;
	}
	else if(left == right)
	{
		printf(" %d", left);
		return;
	}
	center = max(left, right-dp[height]+1);
	printf(" %d", center);
	recursion(left, center-1, height-1);
	recursion(center+1, right, height-1);
}

int main()
{
	int cas, n, m, i;
	cas = 0;
	dp[0] = 1;
	for(i=1; i<31; i++)
	{
		dp[i] = dp[i-1] + dp[i-1];
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		printf("Case %d:", ++cas);
		if(n < dp[m])
		{
			recursion(1, n, m-1);
			printf("\n");
		}
		else
		{
			printf(" Impossible.\n");
		}
	}
	return 0;
}
