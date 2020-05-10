#include <stdio.h>

int main()
{
	int x, y;
	while (scanf("%d%d", &x, &y) == 2)
	{
		if (x > 0 && y > 0)
		{
			puts("1");
		}
		else if (x < 0 && y > 0)
		{
			puts("2");
		}
		else if (x < 0 && y < 0)
		{
			puts("3");
		}
		else
		{
			puts("4");
		}
	}
	return 0;
}
