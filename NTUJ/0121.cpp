#include <stdio.h>

int dp[105][105];

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int n, i, j, v, ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=0, ans=0; i<n; i++)
		{
			for(j=0; j<=i; j++)
			{
				scanf("%d", &v);
				ans = max(ans, dp[i][j]=max(j?dp[i-1][j-1]+v:v, i!=j?dp[i-1][j]+v:v));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
