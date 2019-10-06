#include <stdio.h>

int main()
{
	int n, b, t;
	long long a;
	while (scanf("%lld%d%d", &a, &n, &b) == 3)
	{
		a %= b;
		while (n--)
		{
			scanf("%d%*s", &t);
			a = (a*t) % b;
		}
		printf("%lld\n", a);
	}
	return 0;
}
