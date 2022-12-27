#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<pp, int>;

const int N = 262144;

int res[N];
ppp ary[N];

int main()
{
	int n, i, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i].first.first, &ary[i].first.second);
			ary[i].second = i;
		}
		sort(ary, ary+n);
		priority_queue<pp, vector<pp>, greater<pp> > pq;
		for (i=0, ans=0; i<n; i++)
		{
			if (!pq.size() || pq.top().first >= ary[i].first.first)
			{
				res[ary[i].second] = ++ans;
			}
			else
			{
				res[ary[i].second] = pq.top().second;
				pq.pop();
			}
			pq.emplace(ary[i].first.second, res[ary[i].second]);
		}
		printf("%d\n%d", ans, res[0]);
		for (i=1; i<n; i++)
		{
			printf(" %d", res[i]);
		}
		puts("");
	}
	return 0;
}

