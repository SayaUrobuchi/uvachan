#include <stdio.h>
#include <vector>

long long ans;
int dp[1048576], used[1048576];
std::vector<int> ary[1048576];

int dfs(int now)
{
	int i, t;
	dp[now] = 0;
	for (i=0; i<ary[now].size(); i++)
	{
		t = dfs(ary[now][i])+1;
		if (t > dp[now])
		{
			dp[now] = t;
		}
	}
	ans += dp[now];
	return dp[now];
}

int main()
{
	int cnt, n, i, m, p;
	cnt = 0;
	while (scanf("%d", &n) == 1)
	{
		++cnt;
		for (i=1; i<=n; i++)
		{
			scanf("%d", &m);
			ary[i].clear();
			while (m--)
			{
				scanf("%d", &p);
				ary[i].push_back(p);
				used[p] = cnt;
			}
		}
		for (i=1; i<=n; i++)
		{
			if (used[i] != cnt)
			{
				printf("%d\n", i);
				break;
			}
		}
		ans = 0;
		dfs(i);
		printf("%lld\n", ans);
	}
	return 0;
}
