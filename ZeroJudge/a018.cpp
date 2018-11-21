#include <stdio.h>

long long f(long long n)
{
	if(!n)
	{
		return 1;
	}
	return n * f(n-1);
}

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%lld\n", f(n));
	}
	return 0;
}
