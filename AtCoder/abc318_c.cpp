#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;

int ary[N];

int main()
{
	int n, m, o, i, j;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n, greater<int>());
	long long ans = 0;
	for (i=0; i<n; i+=m)
	{
		long long sum = 0;
		for (j=i; j<n&&j<i+m; j++)
		{
			sum += ary[j];
		}
		ans += min(sum, 1LL*o);
	}
	printf("%lld\n", ans);
	return 0;
}
