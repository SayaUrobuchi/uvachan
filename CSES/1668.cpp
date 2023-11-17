#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;

bool grp[N];
bool used[N];
vector<int> edg[N];

bool dfs(int cur, bool t)
{
	int i;
	bool res = true;
	used[cur] = true;
	grp[cur] = t;
	for (i=0; i<edg[cur].size()&&res; i++)
	{
		int nxt = edg[cur][i];
		if (!used[nxt])
		{
			res = dfs(nxt, !t);
		}
		else if (grp[nxt] == t)
		{
			res = false;
		}
	}
	return res;
}

int main()
{
	int n, m, i, a, b;
	bool ans;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		edg[a].emplace_back(b);
		edg[b].emplace_back(a);
	}
	for (i=1, ans=true; i<=n&&ans; i++)
	{
		if (!used[i])
		{
			ans = dfs(i, false);
		}
	}
	if (ans)
	{
		for (i=1; i<=n; i++)
		{
			printf(i==n?"%d\n":"%d ", grp[i]+1);
		}
	}
	else
	{
		puts("IMPOSSIBLE");
	}
	return 0;
}
