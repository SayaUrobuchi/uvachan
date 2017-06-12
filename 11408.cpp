#include <stdio.h>

int prime[800000], tbl[5000002], dp[5000002], fac[5000002];

int main()
{
	int i, j, k, n, m, pnum;
	prime[0] = 2;
	for(i=3, pnum=1; i<2300; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pnum++] = i;
			for(j=i*i, k=i+i; j<5000001; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	for(i=2; i<=5000000; i++)
	{
		dp[i] = dp[i-1];
		if(i != 2 && i % 2 == 0)
		{
			tbl[i] = 2;
		}
		if(tbl[i] > 0)
		{
			if((i / tbl[i]) % tbl[i])
			{
				fac[i] = fac[i/tbl[i]] + tbl[i];
			}
			else
			{
				fac[i] = fac[i/tbl[i]];
			}
			if(tbl[fac[i]] == 0)
			{
				dp[i] = dp[i-1] + 1;
			}
		}
		else
		{
			dp[i] = dp[i-1] + 1;
			fac[i] = i;
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0)
		{
			break;
		}
		printf("%d\n", dp[m]-dp[n-1]);
	}
	return 0;
}
