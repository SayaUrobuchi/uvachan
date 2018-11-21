#include <stdio.h>

int main()
{
	int n, i, t;
	long long p, q, dp0, dp1;
	while (scanf("%d", &n) == 1)
	{
		dp0 = 0;
		dp1 = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			p = dp0>dp1+t ? dp0 : dp1+t;
			q = dp1>dp0-t ? dp1 : dp0-t;
			dp0 = p;
			dp1 = q;
		}
		printf("%lld\n", dp0>dp1?dp0:dp1);
	}
	return 0;
}
