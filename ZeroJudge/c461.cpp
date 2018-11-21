#include <stdio.h>

int main()
{
	int a, b, c, res;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		a = (a ? 1 : 0);
		b = (b ? 1 : 0);
		res = 0;
		if ((a & b) == c)
		{
			puts("AND");
			res = 1;
		}
		if ((a | b) == c)
		{
			puts("OR");
			res = 1;
		}
		if ((a ^ b) == c)
		{
			puts("XOR");
			res = 1;
		}
		if (!res)
		{
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}
