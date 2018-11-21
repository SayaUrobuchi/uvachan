#include <stdio.h>
#include <math.h>

int dp[10000001], used[10000001], rmq[1000001][22];

int max(int p, int q)
{
	return p>q ? p : q;
}

int recurs(long long now)
{
	if(now < 0)
	{
		return 0;
	}
	if(now >= 1 && now <= 10000000)
	{
		if(used[now])
		{
			return dp[now];
		}
		used[now] = 1;
		return dp[now] = recurs((now&1)?3*now+1:now>>1) + 1;
	}
	return recurs((now&1)?3*now+1:now>>1) + 1;
}

int main()
{
	int n, m, p, q, i, j, k, t, mx;
	used[1] = 1;
	dp[1] = 1;
	for(i=2; i<=1000000; i++)
	{
		if(used[i] == 0)
		{
			recurs(i);
		}
		rmq[i][0] = dp[i];
	}
	rmq[1][0] = dp[1];
	for(i=1, k=2; k<=1000000; i++, k<<=1)
	{
		for(j=1; j+k-1<=1000000; j++)
		{
			rmq[j][i] = max(rmq[j][i-1], rmq[j+(k>>1)][i-1]);
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n > m)
		{
			p = m;
			q = n;
		}
		else
		{
			p = n;
			q = m;
		}
		k = log2(q-p+1);
		printf("%d %d %d\n", n, m, max(rmq[p][k], rmq[q-(1<<k)+1][k]));
	}
	return 0;
}
