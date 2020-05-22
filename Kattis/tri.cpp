#include <stdio.h>

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if (a+b == c)
		{
			printf("%d+%d=%d\n", a, b, c);
		}
		else if (a-b == c)
		{
			printf("%d-%d=%d\n", a, b, c);
		}
		else if (a*b == c)
		{
			printf("%d*%d=%d\n", a, b, c);
		}
		else if (a == c*b)
		{
			printf("%d/%d=%d\n", a, b, c);
		}
		else if (a == b+c)
		{
			printf("%d=%d+%d\n", a, b, c);
		}
		else if (a == b-c)
		{
			printf("%d=%d-%d\n", a, b, c);
		}
		else if (a == b*c)
		{
			printf("%d=%d*%d\n", a, b, c);
		}
		else if (a*c == b)
		{
			printf("%d=%d/%d\n", a, b, c);
		}
	}
	return 0;
}
