#include <stdio.h>

int gcd(int p, int q)
{
	while ((p%=q) && (q%=p));
	return p+q;
}

int main()
{
	int p, q, r;
	while (scanf("%d%d%d", &p, &q, &r) == 3)
	{
		puts(p*q/gcd(p, q)<=r?"yes":"no");
	}
	return 0;
}
