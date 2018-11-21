#include <stdio.h>

int gcd(int p, int q)
{
	if(p % q)
	{
		return gcd(q, p%q);
	}
	return q;
}

int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) == 2)
	{
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
