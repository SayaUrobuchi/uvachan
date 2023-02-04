#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
using pp = pair<int, int>;

const int M = 100005;

int ucnt, tbl[M];

int get_next(int cur, int step, int lim)
{
	for (; cur<=lim&&tbl[cur]!=ucnt; cur+=step);
	return cur;
}

int main()
{
	int count, n, m, i, j, t, mx, ans, cur, step, lim;
	bool gg;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		++ucnt;
		for (i=0, lim=0; i<n; i++)
		{
			scanf("%d", &t);
			tbl[t] = ucnt;
			lim = max(lim, t);
		}
		priority_queue<pp, vector<pp>, greater<pp> > pq;
		for (i=1, mx=0, gg=false; i<=m&&!gg; i++)
		{
			j = get_next(i, i, lim);
			if (j > lim)
			{
				gg = true;
			}
			mx = max(mx, j);
			pq.emplace(j, i);
		}
		if (gg)
		{
			puts("-1");
		}
		else
		{
			ans = mx - pq.top().first;
			while (pq.size())
			{
				tie(cur, step) = pq.top();
				pq.pop();
				t = get_next(cur+step, step, lim);
				if (t > lim)
				{
					break;
				}
				mx = max(mx, t);
				pq.emplace(t, step);
				ans = min(ans, mx-pq.top().first);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
