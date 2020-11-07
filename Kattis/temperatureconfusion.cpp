#include <iostream>

long long gcd(long long p, long long q)
{
	while ((p%=q)&&(q%=p));
	return p+q;
}

int main()
{
	long long a, b, c;
	while (scanf("%lld/%lld", &a, &b) == 2)
	{
		a -= (b<<5);
		a *= 5;
		b *= 9;
		c = gcd(std::abs(a), b);
		printf("%lld/%lld\n", a/c, b/c);
	}
	return 0;
}
