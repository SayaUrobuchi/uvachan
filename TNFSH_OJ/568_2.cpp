#include<iostream>
#include <vector>
using namespace std;

const int N = 2048;

int ucnt;
int used[N][N];
long long dis[N], cost[N][N], pre[N];
vector<int> v[N], w[N];
vector<int> qq, qs;

void bfs(int st)
{
	int i, j, k, cur, cs, nxt, ns;
	long long cw, nw;
	qq.clear();
	qq.push_back(st);
	qs.clear();
	qs.push_back(0);
	used[st][0] = ++ucnt;
	cost[st][0] = 0;
	for (i=0; i<qq.size(); i++)
	{
		cur = qq[i];
		cs = qs[i];
		cw = cost[cur][cs];
		pre[cur] = cw;
		if (dis[cur] > cw * cs)
		{
			dis[cur] = cw * cs;
		}
		for (j=0; j<v[cur].size(); j++)
		{
			nxt = v[cur][j];
			k = w[cur][j];
			ns = cs + 1;
			nw = cw + k;
			if (nw < pre[nxt])
			{
				if (nw < cost[nxt][ns])
				{
					cost[nxt][ns] = nw;
					if (used[nxt][ns] != ucnt)
					{
						used[nxt][ns] = ucnt;
						qq.push_back(nxt);
						qs.push_back(ns);
					}
				}
			}
		}
	}
}

int main() {
	int n, m, i, j, k, t, u, st, p, q, r;
	while (scanf("%d%d%d", &n, &m, &st) == 3)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
			w[i].clear();
			dis[i] = 1e18;
			pre[i] = 1e18;
			for (j=0; j<=n; j++)
			{
				cost[i][j] = 1e18;
			}
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			v[p].push_back(q);
			w[p].push_back(r);
			v[q].push_back(p);
			w[q].push_back(r);
		}
		bfs(st);
		printf("%lld", dis[1]);
		for (i=2; i<=n; i++)
		{
			printf(" %lld", dis[i]);
		}
		puts(" ");
	}
	return 0;
}

