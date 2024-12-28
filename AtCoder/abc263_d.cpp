#include <iostream>
using namespace std;

const int N = 200005;

int ary[N];
long long ll[N], rr[N];

int main()
{
	int n, i, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		ll[i] = min(a*1LL*i, ll[i-1]+ary[i]);
	}
	long long ans = ll[n];
	for (i=n; i>0; i--)
	{
		rr[i] = min(b*1LL*(n-i+1), rr[i+1]+ary[i]);
		ans = min(ans, ll[i-1]+rr[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
