#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int used[262144], ucnt;
vector<int> v[262144];
vector<int> path;

void dfs(int cur)
{
	int i, nxt;
	used[cur] = ucnt;
	path.emplace_back(cur);
	for (i=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		if (used[nxt] != ucnt)
		{
			dfs(nxt);
			path.emplace_back(cur);
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
		for (i=1; i<=n; i++)
		{
			sort(v[i].begin(), v[i].end());
		}
		path.clear();
		++ucnt;
		dfs(1);
		printf("%d", path[0]);
		for (i=1; i<path.size(); i++)
		{
			printf(" %d", path[i]);
		}
		puts("");
	}
	return 0;
}

