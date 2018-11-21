#include <stdio.h>

int j;
int dp[1048576], tbl[1048576], ary[1048576];

int calc(int n)
{
	int t, k, c;
	if (dp[n])
	{
		return dp[n];
	}
	t = n;
	if (t & 1)
	{
		k = (tbl[t] ? tbl[t] : t);
	}
	else
	{
		k = 2;
	}
	c = 1;
	while (!(t%k))
	{
		t /= k;
		++c;
	}
	return dp[n] = calc(t) * c;
}

int bs(int n)
{
	int l, r, c, res;
	res = 0;
	for (l=0, r=j-1; l<=r; )
	{
		c = ((l+r)>>1);
		if (n >= ary[c])
		{
			res = c+1;
			l = c+1;
		}
		else
		{
			r = c-1;
		}
	}
	return res;
}

int main()
{
	int i, k, cas, count, n, m;
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
	dp[1] = 1;
	ary[0] = 1;
	for (i=1, j=1; i<1048576; j++)
	{
		ary[j] = ary[j-1] + calc(i);
		i = ary[j];
	}
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		printf("Case %d: %d\n", ++cas, bs(m)-bs(n-1));
	}
	return 0;
}
