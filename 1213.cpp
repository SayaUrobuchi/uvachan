#include <stdio.h>

int pn, pri[1120], tbl[1125];
int dp[1125][15];

int main()
{
	int i, j, k, n, m;
	pn = 0;
	pri[pn++] = 2;
	for (i=3; i<35; i+=2)
	{
		if (!tbl[i])
		{
			pri[pn++] = i;
			for (j=i*i, k=i+i; j<=1120; j+=k)
			{
				tbl[j] = 1;
			}
		}
	}
	for (; i<=1120; i+=2)
	{
		if (!tbl[i])
		{
			pri[pn++] = i;
		}
	}
	dp[0][0] = 1;
	for (i=0; i<pn; i++)
	{
		for (j=14; j>=1; j--)
		{
			for (k=pri[i]; k<=1120; k++)
			{
				dp[k][j] += dp[k-pri[i]][j-1];
			}
		}
	}
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}
