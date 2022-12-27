#include <iostream>
#include <queue>
using namespace std;
using pp = pair<long long, int>;

int ary[262144];
long long ans[262144];

int main()
{
	int n, i, t, nxt;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		priority_queue<pp, vector<pp>, greater<pp> > pq;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			pq.emplace((long long)t, i);
			ans[i] = t;
		}
		while (pq.size())
		{
			pp cur = pq.top();
			pq.pop();
			nxt = (cur.second+1) % n;
			if (ans[nxt] > cur.first + ary[cur.second])
			{
				ans[nxt] = cur.first + ary[cur.second];
				pq.emplace(ans[nxt], nxt);
			}
		}
		for (i=0; i<n; i++)
		{
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}

