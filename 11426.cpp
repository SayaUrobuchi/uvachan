#include <stdio.h>

int tbl[4000001];
long long dp[4000001];

int main()
{
	int n, i, j, k;
	for(i=1; i<=4000000; i++)
	{
		tbl[i] = i;
	}
	tbl[2] = 1;
	for(i=4; i<=4000000; i+=2)
	{
		tbl[i] >>= 1;
	}
	for(i=3; i<=2000000; i+=2)
	{
		if(tbl[i] == i)
		{
			tbl[i]--;
			for(j=i+i; j<=4000000; j+=i)
			{
				tbl[j] = (tbl[j] / i) * (i-1);
			}
		}
	}
	for(; i<=4000000; i+=2)
	{
		tbl[i] -= (tbl[i] == i);
	}
	for(i=1; i<=2000000; i++)
	{
		for(j=i+i, k=2; j<=4000000; j+=i, k++)
		{
			dp[j] += i * tbl[k];
		}
	}
	for(i=2; i<=4000000; i++)
	{
		dp[i] += dp[i-1];
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}
