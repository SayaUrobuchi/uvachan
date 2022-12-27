#include <iostream>
using namespace std;

int stk[200005];
long long sum[200005];

int main()
{
	int n, a, b, c, i, m, f, t;
	long long ans;
	scanf("%d%d%d", &n, &a, &b);
	for (i=1, m=-1, f=0, ans=-1e18; i<=n; i++)
	{
		scanf("%d", &t);
		sum[i] = sum[i-1] + t;
		if (i-a >= 0)
		{
			c = i-a;
			for (; m>=f&&sum[c]<=sum[stk[m]]; --m);
			stk[++m] = c;
			ans = max(ans, sum[i]-sum[stk[f]]);
			if (stk[f] == i-b)
			{
				++f;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}