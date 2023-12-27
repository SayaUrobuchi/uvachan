#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int N = 100005;

int n;
int bit[N];
pp ary[N];

int real_q(int t)
{
	int ret = 0;
	for (; t; t-=(t&-t))
	{
		ret += bit[t];
	}
	return ret;
}

int query(int a, int b)
{
	if (a > b)
	{
		return 0;
	}
	return real_q(b) - real_q(a-1);
}

void update(int pos, int val)
{
	for (; pos<=n; pos+=(pos&-pos))
	{
		bit[pos] += val;
	}
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i].first);
		ary[i].second = i;
	}
	sort(ary+1, ary+1+n);
	long long ans;
	for (i=1, ans=0; i<=n; i++)
	{
		int pos = ary[i].second;
		int l = pos-1 - query(1, pos-1);
		int r = query(pos+1, n);
		ans += (long long)l * r;
		update(pos, 1);
	}
	printf("%lld\n", ans);
	return 0;
}
