#include <stdio.h>

int main()
{
	int a, n, b, p, q;
	while (scanf("%d%d%d", &a, &n, &b) == 3)
	{
		while (n--)
		{
			scanf("%d%d", &p, &q);
			a += p*q;
		}
		a -= b;
		a >>= 2;
		printf("%d\n", a);
	}
	return 0;
}
