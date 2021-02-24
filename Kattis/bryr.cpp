#include <iostream>
#include <vector>
using namespace std;

int ucnt;
vector<int> qq, qs, used, id;
vector<vector<int> > v;
vector<pair<int, int> > edg;

void bfs(int st, int c)
{
	int i, j, now, nxt;
	qq.clear();
	qq.emplace_back(st);
	++ucnt;
	used[st] = ucnt;
	for (i=0; i<qq.size(); i++)
	{
		now = qq[i];
		id[now] = c;
		for (j=0; j<v[now].size(); j++)
		{
			nxt = v[now][j];
			if (used[nxt] != ucnt)
			{
				used[nxt] = ucnt;
				qq.emplace_back(nxt);
			}
		}
	}
}

int bfs2(int st, int ed)
{
	int i, j, now, nxt, ns;
	qq.clear();
	qq.emplace_back(st);
	qs.clear();
	qs.emplace_back(0);
	++ucnt;
	used[st] = ucnt;
	for (i=0; i<qq.size(); i++)
	{
		now = qq[i];
		ns = qs[i];
		if (now == ed)
		{
			return ns;
		}
		for (j=0; j<v[now].size(); j++)
		{
			nxt = v[now][j];
			if (used[nxt] != ucnt)
			{
				used[nxt] = ucnt;
				qq.emplace_back(nxt);
				qs.emplace_back(ns+1);
			}
		}
	}
	return -1;
}

int main()
{
	int n, m, a, b, c, i, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		edg.clear();
		used.resize(n+1);
		id.resize(n+1);
		v.resize(n+1);
		for (i=1; i<=n; i++)
		{
			v[i].clear();
			id[i] = -1;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (c)
			{
				edg.emplace_back(a, b);
			}
			else
			{
				v[a].emplace_back(b);
				v[b].emplace_back(a);
			}
		}
		bfs(1, 0);
		ans = 0;
		if (id[n])
		{
			bfs(n, 1);
			for (i=2, a=2; i<n; i++)
			{
				if (id[i] == -1)
				{
					bfs(i, a);
					++a;
				}
			}
			for (i=0; i<a; i++)
			{
				v[i].clear();
			}
			for (i=0; i<edg.size(); i++)
			{
				b = id[edg[i].first];
				c = id[edg[i].second];
				if (b != c)
				{
					v[b].emplace_back(c);
					v[c].emplace_back(b);
				}
			}
			ans = bfs2(0, 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
