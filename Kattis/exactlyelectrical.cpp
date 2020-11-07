#include <iostream>

int main()
{
	int x0, x1, y0, y1, d, dx, dy;
	while (scanf("%d%d%d%d%d", &x0, &y0, &x1, &y1, &d) == 5)
	{
		dx = std::abs(x0-x1);
		dy = std::abs(y0-y1);
		if (dx+dy <= d && ((dx+dy)&1) == (d&1))
		{
			puts("Y");
		}
		else
		{
			puts("N");
		}
	}
	return 0;
}
