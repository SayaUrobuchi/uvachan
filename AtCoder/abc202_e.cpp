#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 262144;
const int LOGN = 19;

int step;
int par[N][LOGN];
int depth[N], id[N];
vector<int> v[N], edg[N];
vector<pair<int, int> > que;

int step_up(int cur, int k)
{
	int i;
	if (cur < 0)
	{
		return -cur;
	}
	for (i=0; k; ++i, k>>=1)
	{
		if (k & 1)
		{
			cur = par[cur][i];
		}
	}
	return id[cur];
}

bool comp(const int &a, const int &b)
{
	int as = step_up(a, step);
	int bs = step_up(b, step);
	return as < bs;
}

int main()
{
	int n, i, j, p, q, c, d, m, a, b;
	for (i=0; i<LOGN; i++)
	{
		par[1][i] = -1;
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<=n; i++)
		{
			v[i].clear();
			edg[i].clear();
		}
		for (i=2; i<=n; i++)
		{
			scanf("%d", &par[i][0]);
			edg[par[i][0]].emplace_back(i);
		}
		que.resize(1);
		que[0] = {1, 0};
		for (i=0; i<que.size(); i++)
		{
			c = que[i].first;
			d = que[i].second;
			id[c] = i+1;
			depth[c] = d;
			v[d].emplace_back(c);
			for (j=1; j<LOGN; j++)
			{
				par[c][j] = par[ par[c][j-1] ][j-1];
			}
			for (j=0; j<edg[c].size(); j++)
			{
				que.emplace_back(edg[c][j], d+1);
			}
		}
		scanf("%d", &m);
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			if (depth[a] > b)
			{
				puts("0");
			}
			else
			{
				step = b - depth[a];
				auto at = lower_bound(v[b].begin(), v[b].end(), -id[a], comp);
				auto bt = upper_bound(v[b].begin(), v[b].end(), -id[a], comp);
				printf("%d\n", bt-at);
			}
		}
	}
	return 0;
}

