#include <stdio.h>

int tbl[1048576], dp[1048576], ans[1048576];

int main()
{
	int i, j, k, mx, mxn, t, c, n, count;
	for (i=3; i<1024; i+=2)
	{
		if (!tbl[i])
		{
			for (j=i*i, k=i+i; j<1048576; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	ans[1] = 1;
	dp[1] = 1;
	mx = 0;
	mxn = 1;
	for (i=2; i<=1000000; i++)
	{
		if (i & 1)
		{
			if (tbl[i])
			{
				k = tbl[i];
			}
			else
			{
				k = i;
			}
		}
		else
		{
			k = 2;
		}
		c = 1;
		t = i;
		while (!(t%k))
		{
			t /= k;
			++c;
		}
		dp[i] = dp[t] * c;
		if (dp[i] >= mx)
		{
			mx = dp[i];
			mxn = i;
		}
		ans[i] = mxn;
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
