#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const int N = 16;

int ary[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	pq.emplace(0);
	long long last = -1;
	for (i=0; i<=m; i++)
	{
		while (pq.top() == last)
		{
			pq.pop();
		}
		long long cur = pq.top();
		pq.pop();
		for (j=0; j<n; j++)
		{
			pq.emplace(cur + ary[j]);
		}
		last = cur;
	}
	printf("%lld\n", last);
	return 0;
}
