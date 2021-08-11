#include <iostream>
#include <vector>
using namespace std;

int ucnt;
int dis[1024], used[1024], qq[1024];
vector<int> v[1024];

int main()
{
	int n, m, o, i, j, k, t, u, cur, nxt, best, ans;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0; i<n; i++)
		{
			dis[i] = 1e9;
			v[i].clear();
		}
		++ucnt;
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			dis[t] = 0;
			qq[i] = t;
			used[t] = ucnt;
		}
		for (i=0; i<o; i++)
		{
			scanf("%d%d", &t, &u);
			v[t].emplace_back(u);
			v[u].emplace_back(t);
		}
		for (i=0, j=m; i<j; i++)
		{
			cur = qq[i];
			for (k=0; k<v[cur].size(); k++)
			{
				nxt = v[cur][k];
				if (used[nxt] != ucnt)
				{
					used[nxt] = ucnt;
					dis[nxt] = dis[cur] + 1;
					qq[j] = nxt;
					j++;
				}
			}
		}
		for (i=0, best=-1; i<n; i++)
		{
			if (dis[i] > best)
			{
				best = dis[i];
				ans = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
