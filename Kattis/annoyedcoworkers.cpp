#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using pp = pair<long long, int>;

const int N = 100005;

int add[N];

int main()
{
	int n, m, i;
	long long ans = 0;
	scanf("%d%d", &m, &n);
	priority_queue<pp, vector<pp>, greater<pp> > pq;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d%d", &t, &add[i]);
		pq.emplace(t+add[i], i);
		ans = max(ans, (long long)t);
	}
	for (i=0; i<m; i++)
	{
		long long d;
		int id;
		tie(d, id) = pq.top();
		pq.pop();
		ans = max(ans, d);
		pq.emplace(d+add[id], id);
	}
	printf("%lld\n", ans);
	return 0;
}