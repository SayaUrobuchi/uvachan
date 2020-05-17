#include <stdio.h>

int main()
{
	int n, i;
	double ans, q, qq;
	long long p, pp;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%lld%lf", &p, &q);
			if (i)
			{
				ans += (p-pp) * (q+qq) / 2;
			}
			pp = p;
			qq = q;
		}
		printf("%.10lf\n", ans/1000);
	}
	return 0;
}
