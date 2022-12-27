#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<long long, int>;

const int N = 1048576;

long long pre[N];
pp ary[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, i;
	long long p, q, t, ans;
	cin >> n >> p >> q;
	ary[0] = {0, 0};
	for (i=1; i<=n; i++)
	{
		cin >> pre[i];
		pre[i] += pre[i-1];
		ary[i].first = pre[i] * q - i * p;
		ary[i].second = i;
	}
	sort(ary, ary+n+1);
	for (i=1, ans=0; i<=n; i++)
	{
		t = pre[i]*q - i*p;
		ans += lower_bound(ary, ary+n+1, make_pair(t, i))
			 - lower_bound(ary, ary+n+1, make_pair(t, 0));
	}
	cout << ans << "\n";
	return 0;
}