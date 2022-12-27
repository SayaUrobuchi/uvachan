#include <iostream>
#include <vector>
using namespace std;

int ucnt;
int used[512], dis[512], pre[512];
pair<int, int> ary[262144];
vector<pair<int, int> > edg[512];

int bfs(int st, int ed, int lim)
{
	int i, j, cur, s, nxt;
	vector<pair<int, int> > que;
	que.emplace_back(st, 0);
	++ucnt;
	used[st] = ucnt;
	for (i=0; i<que.size(); i++)
	{
		cur = que[i].first;
		s = que[i].second;
		if (cur == ed)
		{
			return s;
		}
		for (j=0; j<edg[cur].size(); j++)
		{
			nxt = edg[cur][j].first;
			if (lim != edg[cur][j].second && used[nxt] != ucnt)
			{
				used[nxt] = ucnt;
				que.emplace_back(nxt, s+1);
			}
		}
	}
	return -1;
}

int main()
{
	int n, m, i, j, a, b, cur, nxt;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			edg[i].clear();
			dis[i] = -1;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			ary[i] = {a, b};
			edg[a].emplace_back(b, i);
		}
		vector<pair<int, int> > que;
		que.emplace_back(1, 0);
		++ucnt;
		used[1] = ucnt;
		dis[1] = 0;
		for (i=0; i<que.size(); i++)
		{
			cur = que[i].first;
			for (j=0; j<edg[cur].size(); j++)
			{
				nxt = edg[cur][j].first;
				if (used[nxt] != ucnt)
				{
					used[nxt] = ucnt;
					dis[nxt] = dis[cur] + 1;
					pre[nxt] = cur;
					que.emplace_back(nxt, dis[nxt]);
				}
				else if (dis[nxt] == dis[cur] + 1)
				{
					pre[nxt] = -1;
				}
			}
		}
		for (i=0; i<m; i++)
		{
			if (pre[ary[i].second] == ary[i].first)
			{
				printf("%d\n", bfs(1, n, i));
			}
			else
			{
				printf("%d\n", dis[n]);
			}
		}
	}
	return 0;
}

