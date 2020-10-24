#include <iostream>

const int N = 20;

int n, ucnt;
int used[1<<N][N];
long long px[N], py[N], pz[N], dp[1<<N][N];

long long getdis(int p, int q)
{
	return std::abs(px[q]-px[p]) + std::abs(py[q]-py[p]) + std::max(0LL, pz[q]-pz[p]);
}

long long recurs(int st, int cur)
{
	int i;
	long long t, best;
	if (used[st][cur] == ucnt)
	{
		return dp[st][cur];
	}
	used[st][cur] = ucnt;
	if (st == 0)
	{
		return dp[st][cur] = getdis(cur, 0);
	}
	for (i=0, best=1e18; i<n; i++)
	{
		if (st & (1<<i))
		{
			t = recurs(st-(1<<i), i) + getdis(cur, i);
			if (t < best)
			{
				best = t;
			}
		}
	}
	return dp[st][cur] = best;
}

int main()
{
	int i;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%lld%lld%lld", &px[i], &py[i], &pz[i]);
		}
		++ucnt;
		printf("%lld\n", recurs((1<<n)-2, 0));
	}
	return 0;
}
