#include <stdio.h>

int used[52][52];
long long dp[52][52];

long long recursion(int p, int q)
{
	if(used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	if(q == 0 || p == q)
	{
		return dp[p][q]=1;
	}
	else if(p < q)
	{
		return dp[p][q]=0;
	}
	else
	{
		return dp[p][q] = recursion(p-1, q) + recursion(p-1, q-1);
	}
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0)
		{
			break;
		}
		printf("%I64d\n", recursion(n+m-1, m));
	}
	return 0;
}
