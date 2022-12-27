#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, int> ary[262144];

int main()
{
	int n, i;
	long long m, t;
	while (scanf("%d%lld", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%lld%d", &ary[i].first, &ary[i].second);
		}
		sort(ary, ary+n);
		for (i=0, t=0; i<n; i++)
		{
			m -= ary[i].first-t;
			t = ary[i].first;
			if (m < 0)
			{
				break;
			}
			m += ary[i].second;
		}
		printf("%lld\n", t+m);
	}
	return 0;
}

