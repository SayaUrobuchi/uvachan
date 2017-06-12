#include <stdio.h>
#include <math.h>

int tbl[200001];
long long dp[200001];

int main()
{
	int n, i, j, k, l, p, q, sq, temp;
	/*while(scanf("%d", &n) == 1)
	{
		for(i=1, j=0; i<n; i++)
		{
			printf("%d ", k=gcd(i, n));
			j += k;
		}
		printf("TOTAL: %d\n", j);
	}*/
	for(i=1; i<=200000; i++)
	{
		tbl[i] = i;
	}
	tbl[2] = 1;
	for(j=4; j<=200000; j+=2)
	{
		tbl[j] >>= 1;
	}
	for(i=3; i<100000; i+=2)
	{
		if(tbl[i] == i)
		{
			tbl[i]--;
			for(j=i+i; j<=200000; j+=i)
			{
				tbl[j] = (tbl[j] / i) * (i-1);
			}
		}
	}
	for(; i<=200000; i+=2)
	{
		tbl[i] -= (tbl[i] == i);
	}
	for(i=1; i<=100000; i++)
	{
		for(j=i+i, k=2; j<=200000; j+=i, k++)
		{
			dp[j] += i * tbl[k];
		}
	}
	for(i=2; i<=200000; i++)
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
