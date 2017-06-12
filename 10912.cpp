#include <stdio.h>

int dp[27][352];

int main()
{
	int cas, l, s, i, j, k, p, q, sum;
	cas = 0;
	dp[1][1] = 1;
	for(i=2, sum=3; i<27; i++)
	{
		for(j=i; j>1; j--)
		{
			for(k=sum; k>i; k--)
			{
				dp[j][k] += dp[j-1][k-i];
			}
		}
		dp[1][i] = 1;
		sum += i + 1;
	}
	/*for(i=1; i<5; i++)
	{
		for(j=1; j<20; j++)
		{
			printf("%d %d %d\n", i, j, dp[i][j]);
		}
	}*/
	while(scanf("%d%d", &l, &s) == 2)
	{
		if(!l && !s)
		{
			break;
		}
		if(l > 26 || s > 351)
		{
			printf("Case %d: 0\n", ++cas);
		}
		else
		{
			printf("Case %d: %d\n", ++cas, dp[l][s]);
		}
	}
	return 0;
}
