#include <stdio.h>

int gcd(int p, int q)
{
	if(p % q)
	{
		return p / q + gcd(q, p%q);
	}
	return p / q;
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) == 2)
	{
		printf("%d\n", gcd(n, m));
	}
	return 0;
}
