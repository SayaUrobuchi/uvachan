#include <iostream>
#include <algorithm>

double ary[1024];

int main()
{
	int n, i;
	double ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%*s%lf", &ary[i]);
		}
		std::sort(ary, ary+n, std::greater<double>());
		for (i=0, ans=0; i<n; i++)
		{
			ans += ary[i] * (i+1);
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
