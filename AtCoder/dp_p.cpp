#include <iostream>
#include <vector>
using namespace std;

const int W = 0;
const int B = 1;
const int M = 1000000007;

int ucnt;
int used[131072][2], dp[131072][2];
vector<int> v[131072];

int rec(int cur, int typ, int par)
{
	int i, t;
	long long u;
	if (used[cur][typ] == ucnt)
	{
		return dp[cur][typ];
	}
	used[cur][typ] = ucnt;
	dp[cur][typ] = 1;
	for (i=0; i<v[cur].size(); i++)
	{
		t = v[cur][i];
		if (t != par)
		{
			u = rec(t, W, cur);
			if (typ == W)
			{
				u += rec(t, B, cur);
			}
			dp[cur][typ] = (dp[cur][typ] * u) % M;
		}
	}
	//printf("%d %d: %d\n", cur, typ, dp[cur][typ]);
	return dp[cur][typ];
}

int main()
{
	int n, i, a, b;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
		}
		++ucnt;
		for (i=1; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		printf("%d\n", (rec(1, W, 0)+rec(1, B, 0))%M);
	}
	return 0;
}
