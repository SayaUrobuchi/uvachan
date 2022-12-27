#include <iostream>
#include <vector>
using namespace std;

const int N = 262144;
const int M = 1000000007;

int cnt[N][60][2], dp[N];
vector<int> edg[N];
vector<long long> wei[N];

void recurs(int cur, int par)
{
	int i, j, k, nxt, t;
	long long w, res;
	for (i=0; i<60; i++)
	{
		cnt[cur][i][0] = 1;
		cnt[cur][i][1] = 0;
	}
	dp[cur] = 0;
	for (i=0; i<edg[cur].size(); i++)
	{
		nxt = edg[cur][i];
		if (nxt == par)
		{
			continue;
		}
		w = wei[cur][i];
		recurs(nxt, cur);
		dp[cur] = (dp[cur] + dp[nxt]) % M;
		for (j=0; j<60; j++)
		{
			t = ((w >> j) & 1);
			for (k=0; k<2; k++)
			{
				// res = cnt[cur][j][k] * cnt[nxt][j][k^t] * (1LL << j)
				res = (long long)cnt[cur][j][k] * cnt[nxt][j][k^t^1] % M;
				res = res * ((1LL << j) % M) % M;
				dp[cur] = (dp[cur] + res) % M;
				cnt[cur][j][k] += cnt[nxt][j][k^t];
			}
		}
	}
}

int main()
{
	int n, i, a, b;
	long long c;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			edg[i].clear();
			wei[i].clear();
		}
		for (i=1; i<n; i++)
		{
			scanf("%d%d%lld", &a, &b, &c);
			edg[a].emplace_back(b);
			edg[b].emplace_back(a);
			wei[a].emplace_back(c);
			wei[b].emplace_back(c);
		}
		recurs(1, 0);
		printf("%d\n", dp[1]);
	}
	return 0;
}

