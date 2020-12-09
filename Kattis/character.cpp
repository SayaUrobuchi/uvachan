#include <iostream>

long long c[32][32];

int main()
{
	int n, i, j;
	long long ans;
	c[0][0] = 1;
	for (i=1; i<=30; i++)
	{
		c[i][0] = 1;
		for (j=1; j<=i; j++)
		{
			c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=2, ans=0; i<=n; i++)
		{
			ans += c[n][i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
