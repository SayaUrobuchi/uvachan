#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
using pp = pair<long long, int>;

int main()
{
	int i;
	long long n;
	vector<long long> ary;
	scanf("%lld", &n);
	for (i=2; (long long)i*i<=n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;
				ary.emplace_back(i);
			}
		}
	}
	if (n > 1)
	{
		ary.emplace_back(n);
	}
	priority_queue<pp, vector<pp>, greater<pp> > pq;
	pq.emplace(1LL, 0);
	while (!pq.empty())
	{
		long long cur;
		int idx;
		tie(cur, idx) = pq.top();
		pq.pop();
		printf("%lld\n", cur);
		for (i=idx; i<ary.size(); i++)
		{
			if (i == idx || ary[i] != ary[i-1])
			{
				pq.emplace(cur*ary[i], i+1);
			}
		}
	}
	return 0;
}
