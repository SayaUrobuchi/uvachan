#include <iostream>

int main()
{
	int m;
	long long n;
	while (scanf("%lld%d", &n, &m) == 2)
	{
		puts(n<(1LL<<(m+1))?"yes":"no");
	}
	return 0;
}
