#include <iostream>
#include <vector>
using namespace std;

const int D = 17;
const int N = 131072;
const char *rtbl[] = {"Town", "Road"};

int depth[N], anc[N][D+1];
vector<int> v[N];

void build(int cur, int par)
{
	int i;
	depth[cur] = depth[par] + 1;
	anc[cur][0] = par;
	for (i=1; i<D; i++)
	{
		anc[cur][i] = anc[anc[cur][i-1]][i-1];
	}
	for (i=0; i<v[cur].size(); i++)
	{
		if (v[cur][i] != par)
		{
			build(v[cur][i], cur);
		}
	}
}

int lca(int a, int b)
{
	int i;
	if (depth[a] < depth[b])
	{
		swap(a, b);
	}
	for (i=18; depth[a]>=depth[b]; i--)
	{
		if (depth[anc[a][i]] >= depth[b])
		{
			a = anc[a][i];
		}
	}
	for (i=18; a!=b; i--)
	{
		if (anc[a][i] != anc[b][i])
		{
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

bool query(int a, int b)
{
	return (depth[a] + depth[b] - (depth[lca(a, b)] << 1)) & 1;
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
		for (i=1; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		build(1, 0);
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			puts(rtbl[query(a, b)]);
		}
	}
	return 0;
}
