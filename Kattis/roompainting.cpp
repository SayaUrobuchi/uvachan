#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	long long int ans = 0;
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		ans += *lower_bound(ary, ary+n, t) - t;
	}
	printf("%lld\n", ans);
	return 0;
}
