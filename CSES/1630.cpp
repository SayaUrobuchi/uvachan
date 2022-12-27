#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144];

int main()
{
	int n, i, t;
	long long sum, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d%d", &ary[i], &t);
			ans += t;
		}
		sort(ary, ary+n);
		for (i=0, sum=0; i<n; i++)
		{
			sum += ary[i];
			ans -= sum;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

