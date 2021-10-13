#include <iostream>
using namespace std;

const long long M = 1000000000000000000LL;

long long gcd(long long a, long long b)
{
	while ((a%=b) && (b%=a));
	return a+b;
}

int main()
{
	long long a, b, g;
	while (scanf("%lld%lld", &a, &b) == 2)
	{
		g = gcd(a, b);
		a /= g;
		if (M / a < b)
		{
			puts("Large");
		}
		else
		{
			printf("%lld\n", b*a);
		}
	}
	return 0;
}
