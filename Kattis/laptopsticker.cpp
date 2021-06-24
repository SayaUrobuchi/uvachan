#include <iostream>

int main()
{
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		if (c+2 <= a && d+2 <= b)
		{
			puts("1");
		}
		else
		{
			puts("0");
		}
	}
	return 0;
}
