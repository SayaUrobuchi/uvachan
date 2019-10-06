#include <stdio.h>

int main()
{
	long long a, ta, b, tb;
	while (scanf("%lld%lld%lld%lld", &a, &ta, &b, &tb) == 4)
	{
		printf("%lld\n", a*ta+b*tb);
	}
	return 0;
}
