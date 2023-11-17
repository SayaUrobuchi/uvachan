#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;

bool ans;
int depth[N];
vector<int> edg[N], par, path;

void dfs(int cur, int d)
{
	int i;
	depth[cur] = d;
	par.emplace_back(cur);
	for (i=0; i<edg[cur].size()&&!ans; i++)
	{
		int nxt = edg[cur][i];
		if (!depth[nxt])
		{
			dfs(nxt, d+1);
		}
		else if (depth[cur] - depth[nxt] >= 2)
		{
			ans = true;
			for (int j=depth[nxt]; j<=depth[cur]; j++)
			{
				path.emplace_back(par[j-1]);
			}
			path.emplace_back(path[0]);
		}
	}
	par.pop_back();
}

int main()
{
	int n, m, i, a, b;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		edg[a].emplace_back(b);
		edg[b].emplace_back(a);
	}
	ans = false;
	for (i=1; i<=n&&!ans; i++)
	{
		if (!depth[i])
		{
			dfs(i, 1);
		}
	}
	if (ans)
	{
		printf("%d\n", (int)path.size());
		for (i=0; i<path.size(); i++)
		{
			printf("%d%c", path[i], " \n"[i+1==path.size()]);
		}
	}
	else
	{
		puts("IMPOSSIBLE");
	}
	return 0;
}
