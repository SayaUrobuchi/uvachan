#include <iostream>
using namespace std;

int main()
{
	long long n, u;
	int i, k, t;
	while (scanf("%lld", &n) == 1)
	{
		for (i=2, k=1, t=0, u=n; (long long)i*i<=n; i+=k, k=2)
		{
			if (u % i == 0)
			{
				while (u%i == 0)
				{
					u /= i;
					++t;
				}
			}
		}
		if (u > 1)
		{
			++t;
		}
		for (u=0; t>1; t=((t+1)>>1), u++);
		printf("%d\n", u);
	}
	return 0;
}
