/*
	ID: sa072682
	LANG: C
	TASK: kimbits
*/
#include <stdio.h>

int dp[32][32];

int main()
{
	int n, m, i, j, k;
	unsigned int l;
	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);
	scanf("%d%d%u", &n, &m, &l);
	dp[0][0] = 1;
	for(i=1; i<n; i++)
	{
		dp[i][0] = 1;
		for(j=1; j<=m; j++)
		{
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			/*printf("%d %d: %d\n", i, j, dp[i][j]);*/
		}
	}
	for(i=n, l--; i; i--)
	{
		for(j=0, k=0; j<=m; j++)
		{
			k += dp[i-1][j];
		}
		/*printf("\n***%d***\n", k);*/
		if(k > l)
		{
			printf("0");
		}
		else
		{
			printf("1");
			l -= k;
			m--;
		}
	}
	printf("\n");
	scanf(" ");
	return 0;
}
