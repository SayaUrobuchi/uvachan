#include <stdio.h>

int dp[505][505];

int gcd(int p, int q)
{
	if(dp[p][q])
	{
		return dp[p][q];
	}
	if(p % q)
	{
		return dp[p][q]=gcd(q, p%q);
	}
	return dp[p][q]=q;
}

int main()
{
	int n, i, j, ans;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=1, ans=0; i<n; i++)
		{
			for(j=i+1; j<=n; j++)
			{
				ans += gcd(j, i);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
