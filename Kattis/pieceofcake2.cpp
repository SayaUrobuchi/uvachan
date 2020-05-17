#include <stdio.h>

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if (b+b < a)
		{
			b = a - b;
		}
		if (c+c < a)
		{
			c = a - c;
		}
		printf("%d\n", (b*c)<<2);
	}
	return 0;
}
