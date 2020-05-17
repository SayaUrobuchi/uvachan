#include <stdio.h>

int main()
{
	int n, i;
	double a, b, p, ans;
	while (scanf("%lf%d", &p, &n) == 2)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%lf%lf", &a, &b);
			ans += a*b;
		}
		printf("%.7lf\n", ans*p);
	}
	return 0;
}
