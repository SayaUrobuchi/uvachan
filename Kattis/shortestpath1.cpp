#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using pp = pair<int, int>;

const int NO_PATH = 1e9;
const int N = 10005;

int dis[N];
vector<pp> v[N];

int main()
{
	int n, m, o, i, st;
	while (scanf("%d%d%d%d", &n, &m, &o, &st) == 4)
	{
		for (i=0; i<n; i++)
		{
			v[i].clear();
			dis[i] = NO_PATH;
		}
		for (i=0; i<m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			v[a].emplace_back(b, c);
		}
		priority_queue<pp, vector<pp>, greater<pp> > pq;
		pq.emplace(0, st);
		dis[st] = 0;
		while (!pq.empty())
		{
			int cur, d;
			tie(d, cur) = pq.top();
			pq.pop();
			if (dis[cur] != d)
			{
				continue;
			}
			for (i=0; i<v[cur].size(); i++)
			{
				int nxt, w;
				tie(nxt, w) = v[cur][i];
				if (dis[nxt] > dis[cur] + w)
				{
					dis[nxt] = dis[cur] + w;
					pq.emplace(dis[nxt], nxt);
				}
			}
		}
		for (i=0; i<o; i++)
		{
			int t;
			scanf("%d", &t);
			if (dis[t] == NO_PATH)
			{
				puts("Impossible");
			}
			else
			{
				printf("%d\n", dis[t]);
			}
		}
		puts("");
	}
	return 0;
}
