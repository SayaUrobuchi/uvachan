#include <iostream>
#include <cmath>

int main()
{
	double p, q, mid;
	long long n;
	while (scanf("%lld", &n) == 1)
	{
		for (p=1, q=10.1; q-p>=1e-8; )
		{
			mid = (p+q) / 2;
			if (pow(mid, mid) < n)
			{
				p = mid;
			}
			else
			{
				q = mid;
			}
		}
		printf("%.10lf\n", (p+q)/2);
	}
	return 0;
}
