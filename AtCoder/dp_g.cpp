#include <iostream>
#include <vector>
using namespace std;

int ans;
int ucnt, used[131072];
int dp[131072];
vector<int> v[131072];

void recurs(int cur)
{
	int i, nxt;
	if (used[cur] == ucnt)
	{
		return;
	}
	used[cur] = ucnt;
	dp[cur] = 0;
	for (i=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		recurs(nxt);
		dp[cur] = max(dp[cur], dp[nxt]+1);
	}
	ans = max(ans, dp[cur]);
}

int main()
{
	int n, m, i, a, b;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
		}
		++ucnt;
		ans = -1;
		for (i=1; i<=n; i++)
		{
			recurs(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
