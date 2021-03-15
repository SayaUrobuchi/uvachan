#include <iostream>

int main()
{
	int n, i;
	long long m, best, a, b, c;
	while (scanf("%d%lld", &n, &m) == 2)
	{
		for (i=0, best=0; i<n; i++)
		{
			scanf("%lld%lld%lld", &a, &b, &c);
			best = std::max(best, a*b*c);
		}
		printf("%lld\n", best-m);
	}
	return 0;
}
