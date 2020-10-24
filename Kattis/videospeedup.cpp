#include <iostream>

int main()
{
	int n, m, p, q, i, t, last;
	double ans;
	while (scanf("%d%d%d", &n, &p, &m) == 3)
	{
		scanf("%d", &last);
		for (i=1, ans=last, q=100+p; i<n; i++, q+=p)
		{
			scanf("%d", &t);
			ans += (t-last) * q / 100.0;
			last = t;
		}
		t = m;
		ans += (t-last) * q / 100.0;
		printf("%.8lf\n", ans);
	}
	return 0;
}
