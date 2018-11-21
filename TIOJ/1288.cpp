#include <stdio.h>

int map[105][105], dp[105][105];

int recursion(int p, int q)
{
	return p<0 || q<0 ? 0 : dp[p][q];
}

int max(int p, int q)
{
	return p > q ? p : q;
}

int main()
{
	int n, i, j, ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<=i; j++)
			{
				scanf("%d", &map[i][j]);
				dp[i][j] = map[i][j] + max(recursion(i-1, j-1), recursion(i-1, j));
			}
		}
		for(i=0, ans=0; i<n; i++)
		{
			ans = max(ans, dp[n-1][i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
