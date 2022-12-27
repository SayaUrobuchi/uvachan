#include <iostream>
#include <algorithm>
using namespace std;

long long ary[131072];

int main()
{
	int n, i, t;
	long long m;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &t);
			ary[i] = ary[i-1] + t;
		}
		scanf("%lld", &m);
		printf("%lld\n", m/ary[n]*n + (upper_bound(ary+0, ary+n+1, m%ary[n])-ary));
	}
	return 0;
}

