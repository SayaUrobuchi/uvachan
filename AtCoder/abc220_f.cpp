#include <iostream>
#include <vector>
using namespace std;

const int N = 262144;

int n;
long long dp[N], cnt[N];
vector<int> edg[N];

void recurs(int cur, int par)
{
	int i, child;
	dp[cur] = 0;
	cnt[cur] = 1;
	for (i=0; i<edg[cur].size(); i++)
	{
		child = edg[cur][i];
		if (child != par)
		{
			recurs(child, cur);
			dp[cur] += dp[child] + cnt[child];
			cnt[cur] += cnt[child];
		}
	}
}

void re2(int cur, int par, long long add)
{
	int i, child;
	for (i=0; i<edg[cur].size(); i++)
	{
		child = edg[cur][i];
		if (child != par)
		{
			re2(child, cur, dp[cur]-(dp[child]+cnt[child])+add+(n-cnt[child]));
		}
	}
	dp[cur] += add;
}

int main()
{
	int i, a, b;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			edg[i].clear();
		}
		for (i=1; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			edg[a].emplace_back(b);
			edg[b].emplace_back(a);
		}
		recurs(1, -1);
		re2(1, -1, 0);
		for (i=1; i<=n; i++)
		{
			printf("%lld\n", dp[i]);
		}
	}
	return 0;
}

