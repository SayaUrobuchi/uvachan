#include <stdio.h>

int main()
{
	int count, a, b, c, z;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &a, &b, &z);
		c = a + b;
		a = a*3 - c;
		b = b*3 - c;
		if (a < 0)
		{
			a = 0;
		}
		if (b < 0)
		{
			b = 0;
		}
		printf("%d\n", z*a/(a+b));
	}
	return 0;
}
