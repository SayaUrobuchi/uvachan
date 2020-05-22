#include <stdio.h>

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		a += b;
		b = 0;
		while (a >= c)
		{
			b += a/c;
			a = a%c + a/c;
		}
		printf("%d\n", b);
	}
	return 0;
}