#include <iostream>
#include <vector>
using namespace std;

int depth, id;
vector<int> v[131072];

void dfs(int cur, int par, int d)
{
	int i, nxt;
	if (d > depth)
	{
		depth = d;
		id = cur;
	}
	for (i=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		if (nxt != par)
		{
			dfs(nxt, cur, d+1);
		}
	}
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
		for (i=1; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		depth = -1;
		dfs(1, 0, 0);
		depth = -1;
		dfs(id, 0, 0);
		printf("%d\n", depth+1);
	}
	return 0;
}
