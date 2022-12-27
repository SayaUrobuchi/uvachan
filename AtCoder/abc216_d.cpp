#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pp = pair<int, int>;

queue<int> v[262144];
int tbl[262144];

void add(int id, queue<pp> &que)
{
	int nxt;
	if (v[id].size())
	{
		nxt = v[id].front();
		v[id].pop();
		if (tbl[nxt] != -1)
		{
			que.emplace(id, tbl[nxt]);
		}
		tbl[nxt] = id;
	}
}

int main()
{
	int n, m, i, j, t, siz;
	bool gg;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			tbl[i] = -1;
		}
		queue<pp> que;
		for (i=0; i<m; i++)
		{
			scanf("%d", &siz);
			v[i] = queue<int>();
			for (j=0; j<siz; j++)
			{
				scanf("%d", &t);
				v[i].emplace(t);
			}
			add(i, que);
		}
		for (i=0, gg=false; i<n; i++)
		{
			if (que.empty())
			{
				gg = true;
				break;
			}
			pp nxt = que.front();
			que.pop();
			add(nxt.first, que);
			add(nxt.second, que);
		}
		if (gg)
		{
			puts("No");
		}
		else
		{
			puts("Yes");
		}
	}
	return 0;
}

