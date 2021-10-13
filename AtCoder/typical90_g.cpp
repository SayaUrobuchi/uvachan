#include <iostream>
#include <algorithm>
using namespace std;

int ary[1048576];

int main()
{
	int n, m, i, t, u;
	int *p;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		sort(ary, ary+n);
		scanf("%d", &m);
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			p = lower_bound(ary, ary+n, t);
			u = 2e9;
			if (p != ary+n)
			{
				u = min(u, abs(*p-t));
			}
			if (p != ary)
			{
				u = min(u, abs(p[-1]-t));
			}
			printf("%d\n", u);
		}
	}
	return 0;
}
