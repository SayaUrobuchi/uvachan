#include <stdio.h>
#include <string.h>
#include <math.h>

int prime[800], dp[500001];

int main()
{
	int cas, count, n, m, i, j, k, num, sq;
	cas = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 1;
	prime[0] = 2;
	prime[1] = 3;
	for(i=5, num=2; i<500001; i++)
	{
		n = i;
		sq = sqrt(i) + 1;
		for(j=0, k=0; prime[j]<sq; j++)
		{
			if(!(n % prime[j]))
			{
				k += prime[j];
				while(!((n /= prime[j]) % prime[j]))
				{
					k += prime[j];
				}
				if(n == 1)
				{
					break;
				}
			}
		}
		if(n == i)
		{
			if(n < 800)
			{
				prime[num++] = i;
			}
			dp[i] = 1;
		}
		else
		{
			if(n > 1)
			{
				k += n;
			}
			dp[i] = dp[k] + 1;
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		if(n > m)
		{
			m ^= n ^= m ^= n;
		}
		for(i=n, m++, j=0; i<m; i++)
		{
			if(dp[i] > j)
			{
				j = dp[i];
			}
		}
		printf("Case #%d:\n%d\n", ++cas, j);
	}
	return 0;
}
