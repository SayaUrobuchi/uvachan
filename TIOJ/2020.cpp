#include <stdio.h>

int dp[128][128], used[128][128];

int ggggcd(int p, int q)
{
	int i, res;
	if (p < q)
	{
		i = p;
		p = q;
		q = i;
	}
	if (used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	if (p % q == 0)
	{
		return dp[p][q] = p / q;
	}
	dp[p][q] = 2147483647;
	for (i=1; i+i<=p; i++)
	{
		res = ggggcd(i, q) + ggggcd(p-i, q);
		if (res < dp[p][q])
		{
			dp[p][q] = res;
		}
	}
	for (i=1; i+i<=q; i++)
	{
		res = ggggcd(p, i) + ggggcd(p, q-i);
		if (res < dp[p][q])
		{
			dp[p][q] = res;
		}
	}
	return dp[p][q];
}

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		printf("%d\n", ggggcd(n, m));
	}
	return 0;
}
