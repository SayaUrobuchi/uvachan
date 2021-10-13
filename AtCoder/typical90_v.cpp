#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	while ((a%=b) && (b%=a));
	return a+b;
}

int main()
{
	long long a, b, c, g;
	while (scanf("%lld%lld%lld", &a, &b, &c) == 3)
	{
		g = gcd(gcd(a, b), c);
		printf("%lld\n", (a/g-1)+(b/g-1)+(c/g-1));
	}
	return 0;
}
