#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300005;
const int M = 100000000;

int ary[N];
long long pre[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary+1, ary+n+1);
	for (i=1; i<=n; i++)
	{
		pre[i] = pre[i-1] + ary[i];
	}
	long long ans = 0;
	for (i=1; i<=n; i++)
	{
		int idx = lower_bound(ary+i+1, ary+n+1, M-ary[i]) - ary;
		ans += ary[i] * 1LL * (idx-(i+1));
		ans += pre[idx] - pre[i];
		ans += (ary[i] - M) * 1LL * (n+1-idx);
		ans += pre[n] - pre[idx];
	}
	printf("%lld\n", ans);
	return 0;
}
