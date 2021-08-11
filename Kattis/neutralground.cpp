#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
const int MX = 40*40*3;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int ans, flow;
int ucnt;
int qq[MX], qs[MX], used[MX], from[MX];
vector<pair<int, int> > v[MX];

char buf[1024];

int bfs(int st, int ed)
{
	int i, j, k, f, cur, nxt;
	++ucnt;
	qq[0] = st;
	qs[0] = INF;
	used[st] = ucnt;
	for (i=0, j=1; i<j; i++)
	{
		cur = qq[i];
		if (cur == ed)
		{
			break;
		}
		for (k=0; k<v[cur].size(); k++)
		{
			f = v[cur][k].second;
			if (f)
			{
				nxt = v[cur][k].first;
				if (used[nxt] != ucnt)
				{
					used[nxt] = ucnt;
					from[nxt] = cur;
					qq[j] = nxt;
					qs[j] = min(f, qs[i]);
					j++;
				}
			}
		}
	}
	if (i >= j)
	{
		return 0;
	}
	ans += flow = qs[i];
	return flow;
}

int main()
{
	int n, m, st, ed, shift, i, j, k, id, bid, t, x, y, a, b;
	while (scanf("%d%d", &m, &n) == 2)
	{
		shift = n*m;
		st = shift+shift;
		ed = st+1;
		for (i=0; i<=ed; i++)
		{
			v[i].clear();
		}
		for (i=0, id=0; i<n; i++)
		{
			scanf("%s", buf);
			for (j=0; j<m; j++, id++)
			{
				bid = id + shift;
				for (k=0; k<4; k++)
				{
					x = i+dx[k];
					y = j+dy[k];
					if (x >= 0 && x < n && y >= 0 && y < m)
					{
						t = x*m + y;
						v[bid].emplace_back(t, INF);
					}
				}
				if (buf[j] == 'A')
				{
					v[st].emplace_back(id, INF);
					v[id].emplace_back(bid, INF);
				}
				else if (buf[j] == 'B')
				{
					v[id].emplace_back(bid, INF);
					v[bid].emplace_back(ed, INF);
				}
				else
				{
					v[id].emplace_back(bid, buf[j]-'0');
				}
			}
		}
		ans = 0;
		while (bfs(st, ed))
		{
			for (a=ed, b=from[ed]; a!=st; a=b, b=from[b])
			{
				v[a].emplace_back(b, flow);
				for (i=0; i<v[b].size(); i++)
				{
					if (v[b][i].first == a && v[b][i].second >= flow)
					{
						v[b][i].second -= flow;
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
