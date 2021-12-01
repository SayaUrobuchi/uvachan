#include <iostream>
#include <vector>
using namespace std;

const int ALL = 2;
const int N = 131072;
const int M = 1000000007;

int ary[N];
long long dp[N][4];
vector<int> v[N];

void recurs(int cur, int par)
{
	int c, i, nxt;
	long long t, u;
	c = ary[cur];
	for (i=0, t=1, u=1; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		if (nxt != par)
		{
			recurs(nxt, cur);
			t = (t * (dp[nxt][c] + dp[nxt][ALL])) % M;
			u = (u * (dp[nxt][0] + dp[nxt][1] + (dp[nxt][2]<<1))) % M;
		}
	}
	dp[cur][c] = t;
	dp[cur][c^1] = 0;
	dp[cur][ALL] = (u + M - t) % M;
	//printf(".. %d: %lld %lld %lld\n", cur, dp[cur][0], dp[cur][1], dp[cur][2]);
}

int main()
{
	int n, i, a, b;
	char buf[128];
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%s", buf);
			ary[i] = *buf - 'a';
			v[i].clear();
		}
		for (i=1; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		recurs(1, 0);
		printf("%lld\n", dp[1][ALL]);
	}
	return 0;
}
