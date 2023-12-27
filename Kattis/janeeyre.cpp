#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
using pp = pair<string, int>;
using ppp = pair<int, pp>;

const string TARGET = "Jane Eyre";
const int N = 100005;

char buf[32];
ppp ary[N];

int main()
{
	int n, m, i, t, u;
	scanf("%d%d%d", &n, &m, &t);
	priority_queue<pp, vector<pp>, greater<pp> > pq;
	pq.emplace(TARGET, t);
	for (i=0; i<n; i++)
	{
		scanf(" \"%[^\"]\"%d", buf, &t);
		pq.emplace(buf, t);
	}
	for (i=0; i<m; i++)
	{
		scanf("%d \"%[^\"]\"%d", &t, buf, &u);
		ary[i].first = t;
		ary[i].second.first = buf;
		ary[i].second.second = u;
	}
	sort(ary, ary+m);
	long long cur = 0;
	long long ans;
	for (i=0; ; )
	{
		string s;
		tie(s, u) = pq.top();
		pq.pop();
		cur += u;
		if (s == TARGET)
		{
			ans = cur;
			break;
		}
		for (; i<m&&ary[i].first<=cur; i++)
		{
			pq.emplace(ary[i].second);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
