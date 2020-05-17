#include <stdio.h>

int main()
{
	int n, i;
	double ans, p, q;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%lf%lf", &p, &q);
			ans += p*q;
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
