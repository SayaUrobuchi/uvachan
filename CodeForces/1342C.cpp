#include <stdio.h>

int nn;
int dp[65536];

long long calc(long long int p)
{
	if (p < 0)
	{
		return 0;
	}
	return (p/nn * dp[nn-1]) + dp[p%nn];
}

int main()
{
	int count, a, b, m, i;
	long long p, q;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &a, &b, &m);
		nn = a*b;
		for (i=0; i<nn; i++)
		{
			if (i)
			{
				dp[i] = dp[i-1];
			}
			if (i%a%b != i%b%a)
			{
				dp[i]++;
			}
		}
		for (i=0; i<m; i++)
		{
			scanf("%lld%lld", &p, &q);
			printf("%s%lld", i?" ":"", calc(q) - calc(p-1));
		}
		puts("");
	}
	return 0;
}
