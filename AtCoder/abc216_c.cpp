#include <iostream>
using namespace std;

void recurs(long long n)
{
	if (n == 0)
	{
		return;
	}
	if (n & 1)
	{
		recurs(n-1);
		putchar('A');
	}
	else
	{
		recurs(n>>1);
		putchar('B');
	}
}

int main()
{
	long long n;
	while (scanf("%lld", &n) == 1)
	{
		recurs(n);
		puts("");
	}
	return 0;
}
