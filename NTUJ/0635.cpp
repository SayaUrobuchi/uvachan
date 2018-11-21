#include <stdio.h>

int m, cas;
int used[1001][11][10001], dp[1001][11][10001];

int calc(int a, int n, int b)
{
	int res;
	if(used[a][n][b] == cas)
	{
		return dp[a][n][b];
	}
	used[a][n][b] = cas;
	if(n == 0)
	{
		res = (b+1) % m;
	}
	else if(n == 1 && b == 0)
	{
		res = a % m;
	}
	else if(n == 2 && b == 0)
	{
		res = 0;
	}
	else if(n >= 3 && b == 0)
	{
		res = 1;
	}
	else
	{
		res = calc(a, n-1, calc(a, n, b-1)) % m;
	}
	return dp[a][n][b] = res;
}

int main()
{
	int count, a, n, b;
	cas = 1;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &m, &n, &a, &b);
		printf("Case #%d: %d\n", cas++, calc(a, n, b));
	}
	return 0;
}
