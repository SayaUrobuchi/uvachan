#include <iostream>

int main()
{
	int x, y;
	while (scanf("%d%d", &x, &y) == 2)
	{
		if (y == 1)
		{
			if (x == 0)
			{
				puts("ALL GOOD");
			}
			else
			{
				puts("IMPOSSIBLE");
			}
		}
		else
		{
			printf("%.10lf\n", x/(1.0-y));
		}
	}
	return 0;
}
