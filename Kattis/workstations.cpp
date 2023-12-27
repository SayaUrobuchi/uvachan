#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using pp = pair<int, int>;

const int N = 300005;

pp ary[N];

int main()
{
	int n, m, i, ans;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i].first, &ary[i].second);
	}
	sort(ary, ary+n);
	priority_queue<int, vector<int>, greater<int> > pq;
	for (i=0, ans=0; i<n; i++)
	{
		while (!pq.empty() && pq.top() < ary[i].first - m)
		{
			pq.pop();
		}
		if (!pq.empty() && pq.top() <= ary[i].first)
		{
			pq.pop();
			++ans;
		}
		pq.emplace(ary[i].first + ary[i].second);
	}
	printf("%d\n", ans);
	return 0;
}
