#include <stdio.h>

int ary[1000];
long long dp[1000];

long long ab(long long now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

long long dis(long long p, long long q)
{
	return ab(p-q);
}

long long min(long long p, long long q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int count, n, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if(i)
			{
				if(i == 1)
				{
					dp[1] = dis(ary[1], ary[0]);
				}
				else
				{
					dp[i] = min(dp[i-1] + dis(ary[i], ary[i-1]), dp[i-2] + dis(ary[i], ary[i-2]));
				}
			}
		}
		printf("%I64d\n", dp[n-1]);
	}
	return 0;
}
