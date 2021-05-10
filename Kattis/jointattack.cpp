#include <iostream>

long long a, b;

void recurs(int cur, int lim)
{
	int t;
	scanf("%d", &t);
	if (cur == lim)
	{
		a = 1;
		b = t;
	}
	else
	{
		recurs(cur+1, lim);
		a += b*t;
		std::swap(a, b);
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		recurs(1, n);
		printf("%lld/%lld\n", b, a);
	}
	return 0;
}
