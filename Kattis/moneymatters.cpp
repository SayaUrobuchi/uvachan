#include <iostream>
#include <vector>
using namespace std;

const int N = 10005;

int ary[N];
bool used[N];
vector<int> v[N];

int dfs(int cur)
{
	int i;
	int ret = ary[cur];
	used[cur] = true;
	for (i=0; i<v[cur].size(); i++)
	{
		int nxt = v[cur][i];
		if (!used[nxt])
		{
			ret += dfs(nxt);
		}
	}
	return ret;
}

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	bool is_ok = true;
	for (i=0; i<n&&is_ok; i++)
	{
		if (!used[i])
		{
			is_ok = !dfs(i);
		}
	}
	puts(is_ok ? "POSSIBLE" : "IMPOSSIBLE");
	return 0;
}