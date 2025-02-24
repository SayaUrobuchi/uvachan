#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;
using pp = pair<ll, int>;
using pq_t = priority_queue<pp>;

const int N = 200005;
const int A = 0;
const int B = 1;
const int REMOVED = -1;

int stat[N];
ll ary[N], bry[N];

int main()
{
	int n, m, i;
	ll o;
	scanf("%d%d%lld", &n, &m, &o);
	pq_t abig, bbig, dbig;
	ll cur = 0;
	for (i=0; i<n; i++)
	{
		scanf("%lld%lld", &ary[i], &bry[i]);
		abig.emplace(ary[i], i);
		dbig.emplace(ary[i]-bry[i], i);
		stat[i] = A;
		cur += ary[i];
	}
	for (i=0; i<m; i++)
	{
		int id;
		ll diff;
		tie(diff, id) = dbig.top();
		dbig.pop();
		bbig.emplace(bry[id], id);
		stat[id] = B;
		cur -= diff;
	}
	int ans = n;
	while (cur > o)
	{
		while (!abig.empty() && stat[abig.top().second] != A)
		{
			abig.pop();
		}
		while (!dbig.empty() && stat[dbig.top().second] != A)
		{
			dbig.pop();
		}
		long long a = 0;
		if (!abig.empty())
		{
			a = abig.top().first;
		}
		long long b = 0;
		if (!bbig.empty())
		{
			b = bbig.top().first;
			if (!dbig.empty())
			{
				b += dbig.top().first;
			}
		}
		if (a >= b)
		{
			stat[abig.top().second] = REMOVED;
			abig.pop();
			cur -= a;
		}
		else
		{
			stat[bbig.top().second] = REMOVED;
			bbig.pop();
			if (!dbig.empty())
			{
				int id = dbig.top().second;
				stat[id] = B;
				dbig.pop();
				bbig.emplace(bry[id], id);
			}
			cur -= b;
		}
		--ans;
	}
	printf("%d\n", ans);
	return 0;
}
