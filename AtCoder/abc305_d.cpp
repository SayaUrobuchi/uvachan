#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;

int ary[N], sum[N];

int main()
{
	int n, m, i;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		sum[i] = sum[i-1];
		if (i > 1 && (i & 1))
		{
			sum[i] += ary[i] - ary[i-1];
		}
	}
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int ai = lower_bound(ary+1, ary+n+1, a) - ary;
		int bi = upper_bound(ary+1, ary+n+1, b) - ary;
		--bi;
		int ans = sum[bi] - sum[ai];
		if (ai & 1)
		{
			ans += ary[ai] - a;
		}
		if (!(bi & 1))
		{
			ans += b - ary[bi];
		}
		printf("%d\n", ans);
	}
	return 0;
}
