#include <iostream>
#include <vector>
using namespace std;

vector<int> v[131072], qq[2];

void dfs(int cur, int par, int depth)
{
	int i, nxt;
	qq[depth&1].emplace_back(cur);
	for (i=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		if (nxt != par)
		{
			dfs(nxt, cur, depth+1);
		}
	}
}

int main()
{
	int n, i, t, a, b;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
		}
		qq[0].clear();
		qq[1].clear();
		for (i=1; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		dfs(1, 0, 0);
		t = 0;
		if (qq[1].size() > qq[0].size())
		{
			t = 1;
		}
		for (i=0; i+i<n; i++)
		{
			printf("%s%d", i?" ":"", qq[t][i]);
		}
		puts("");
	}
	return 0;
}
