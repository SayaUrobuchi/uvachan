#include <stdio.h>
#include <math.h>

int main()
{
	int x, y, x1, x2, y1, y2, dx, dy;
	while (scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2) == 6)
	{
		if (x >= x1 && x <= x2)
		{
			printf("%d\n", y>y2?y-y2:y1-y);
		}
		else if (y >= y1 && y <= y2)
		{
			printf("%d\n", x>x2?x-x2:x1-x);
		}
		else
		{
			dx = x>x2?x-x2:x1-x;
			dy = y>y2?y-y2:y1-y;
			printf("%.10lf\n", sqrt(dx*dx+dy*dy));
		}
	}
	return 0;
}
