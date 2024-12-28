#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lim;
int ucnt, used[200005];
vector<pair<int, int> > v[200005];

void dfs(int cur)
{
	int i, nxt, w;
	used[cur] = ucnt;
	for (i=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i].first;
		w = v[cur][i].second;
		if (used[nxt] != ucnt && w > lim)
		{
			dfs(nxt);
		}
	}
}

int main()
{
	int n, m, i, j, a, b, c, p, q, mid;
	int ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			v[a].emplace_back(b, c);
			v[b].emplace_back(a, c);
		}
		for (p=0, q=1e9+10, ans=0; p<=q; )
		{
			mid = ((p+q) >> 1);
			lim = mid;
			++ucnt;
			for (i=1, j=0; i<=n&&j<3; i++)
			{
				if (used[i] != ucnt)
				{
					dfs(i);
					++j;
				}
			}
			if (j >= 3)
			{
				q = mid - 1;
				ans = mid;
			}
			else
			{
				p = mid + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

