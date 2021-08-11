#include <iostream>

int main()
{
	int a, b, c, d, x, y;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		if (a < b)
		{
			x = d-c;
			if (x < 1)
			{
				x = 1;
			}
			y = c-x;
		}
		else
		{
			x = c-1;
			y = 1;
		}
		printf("%lld\n", (long long)x*a+(long long)y*b);
	}
	return 0;
}
