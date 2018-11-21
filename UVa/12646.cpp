#include <stdio.h>

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if (a != b && a != c)
		{
			puts("A");
		}
		else if (b != a && b != c)
		{
			puts("B");
		}
		else if (c != a && c != b)
		{
			puts("C");
		}
		else
		{
			puts("*");
		}
	}
	return 0;
}
