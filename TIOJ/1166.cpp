#include <stdio.h>

int gcd(int p, int q)
{
	return p % q ? gcd(q, p%q) : q;
}

int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) == 2)
	{
		if(a == 0 && b == 0)
		{
			break;
		}
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
