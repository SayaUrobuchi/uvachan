#include <stdio.h>
#include <string.h>

long long dp[22501], times[52];

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int min(int p, int q)
{
    if(p < q)
    {
		return p;
	}
	return q;
}

int main()
{
	int count, cas, n, i, j, in, sum, chk, ans, lim;
	times[0] = 1;
	for(i=1; i<52; i++)
	{
		times[i] = times[i-1] * 2;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for(i=0, sum=0; i<n; i++)
		{
			scanf("%d", &in);
			sum += in;
			lim = min(22500, sum);
			for(j=lim; j>in; j--)
			{
				dp[j] |= dp[j-in] << 1;
			}
			dp[in] |= 1;
		}
		n--;
		n /= 2;
		for(i=1, chk=22500; i<=22500; i++)
		{
			if(dp[i] & times[n])
			{
				if(ab(i - (sum - i)) < chk)
				{
					chk = ab(i - (sum-i));
					ans = i;
				}
			}
		}
		if(ans > sum-ans)
		{
			printf("%d %d\n", sum-ans, ans);
		}
		else
		{
			printf("%d %d\n", ans, sum-ans);
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
