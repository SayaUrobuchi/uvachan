#include <iostream>
#include <vector>
using namespace std;

const int N = 262144;

int ucnt, used[N], dis[N];
vector<int> v[N], gp[N];
vector<pair<int, int> > que;

int main()
{
	int n, m, i, j, k, t, u, d, cur;
	while (cin >> n >> m)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
			dis[i] = -1;
		}
		for (i=0; i<m; i++)
		{
			cin >> t;
			gp[i].resize(t);
			for (j=0; j<t; j++)
			{
				cin >> gp[i][j];
				v[gp[i][j]].emplace_back(i);
			}
		}
		dis[1] = 0;
		que.clear();
		++ucnt;
		for (i=0; i<v[1].size(); i++)
		{
			t = v[1][i];
			que.emplace_back(t, 0);
			used[t] = ucnt;
		}
		for (i=0; i<que.size(); i++)
		{
			cur = que[i].first;
			d = que[i].second;
			for (j=0; j<gp[cur].size(); j++)
			{
				t = gp[cur][j];
				if (dis[t] == -1)
				{
					dis[t] = d+1;
					for (k=0; k<v[t].size(); k++)
					{
						u = v[t][k];
						if (used[u] != ucnt)
						{
							used[u] = ucnt;
							que.emplace_back(u, d+1);
						}
					}
				}
			}
		}
		for (i=1; i<=n; i++)
		{
			cout << dis[i] << "\n";
		}
	}
	return 0;
}
