#include <iostream>
#include <cmath>

int main()
{
	int n, i;
	long long a, b, c, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, a=0, b=0, c=0; i<n; i++)
		{
			scanf("%lld", &t);
			a += std::abs(t);
			b += t*t;
			c = std::max(std::abs(t), c);
		}
		printf("%lld\n%.16lf\n%lld\n", a, sqrt(b), c);
	}
	return 0;
}
