#include <iostream>

long long recurs(long long n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n & 1)
	{
		return recurs(n*3+1) + n;
	}
	return recurs(n>>1) + n;
}

int main()
{
	long long n;
	while (scanf("%lld", &n) == 1)
	{
		printf("%lld\n", recurs(n));
	}
	return 0;
}