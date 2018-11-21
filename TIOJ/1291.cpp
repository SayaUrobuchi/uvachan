#include <stdio.h>

int dp[205][205];
char used[205][205];

int recursion(int p, int q)
{
	int i;
	if(used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	if(p > q)
	{
		return dp[p][q]=0;
	}
	if(p == 0)
	{
		return dp[p][q]=0;
	}
	if(q == 1)
	{
		return dp[p][q]=1;
	}
	return dp[p][q]=(recursion(p-1, q-1)+recursion(p, q-1)*p)%1000000;
}

int main()
{
	int n, m, i, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=1, ans=0; i<=n; i++)
		{
			ans += recursion(i, m);
			ans %= 1000000;
		}
		printf("%d\n", ans);
	}
	return 0;
}
