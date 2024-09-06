#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pq_t = priority_queue<int, vector<int>, greater<int> >;

vector<int> v[3];

void adjust(pq_t &pq, long long &sum, int lim)
{
	while (pq.size() > lim)
	{
		sum -= pq.top();
		pq.pop();
	}
}

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
	}
	for (i=0; i<3; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	pq_t pq;
	long long sum, ans;
	for (i=0, sum=0; i<v[0].size(); i++)
	{
		pq.emplace(v[0][i]);
		sum += v[0][i];
	}
	adjust(pq, sum, m);
	ans = sum;
	while (--m > 0 && v[2].size())
	{
		int t = v[2].back();
		v[2].pop_back();
		while (t-- && v[1].size())
		{
			pq.emplace(v[1].back());
			sum += v[1].back();
			v[1].pop_back();
		}
		adjust(pq, sum, m);
		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
