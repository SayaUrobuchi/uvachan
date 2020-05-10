#include <stdio.h>

int main()
{
	long long p, q;
	while (scanf("%lld%lld", &p, &q) == 2)
	{
		printf("%lld\n", p>q ? p-q : q-p);
	}
	return 0;
}
