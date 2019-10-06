#include <stdio.h>

int main()
{
	int count, a, b, c;
	c = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &a, &b);
		a >>= 1;
		b >>= 1;
		a -= b;
		if (a < 0)
		{
			a += 3;
		}
		if (a == 1)
		{
			++c;
		}
		else if (a == 2)
		{
			--c;
		}
	}
	puts(c?(c>0?"The princess wins.":"The prince wins."):"The referee wins.");
	return 0;
}
