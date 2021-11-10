#include <iostream>
#include <vector>
using namespace std;

int ucnt, cnt;
int used[131072];
vector<int> v[131072], rv[131072];
vector<int> ord;

void dfs0(int cur)
{
	int i, nxt;
	used[cur] = ucnt;
	for (i=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		if (used[nxt] != ucnt)
		{
			dfs0(nxt);
		}
	}
	ord.emplace_back(cur);
}

void dfs1(int cur)
{
	int i, nxt;
	used[cur] = ucnt;
	++cnt;
	for (i=0; i<rv[cur].size(); i++)
	{
		nxt = rv[cur][i];
		if (used[nxt] != ucnt)
		{
			dfs1(nxt);
		}
	}
}

int main()
{
	int n, m, i, a, b;
	long long ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
			rv[i].clear();
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
			rv[b].emplace_back(a);
		}
		++ucnt;
		ord.clear();
		for (i=1; i<=n; i++)
		{
			if (used[i] != ucnt)
			{
				dfs0(i);
			}
		}
		++ucnt;
		for (i=ord.size()-1, ans=0; i>=0; i--)
		{
			if (used[ord[i]] != ucnt)
			{
				cnt = 0;
				dfs1(ord[i]);
				ans += (long long)cnt * (cnt-1) / 2;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
