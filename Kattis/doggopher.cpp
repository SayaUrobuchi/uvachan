#include <iostream>

double getdis(double x, double y)
{
	return x*x + y*y;
}

int main()
{
	double gx, gy, dx, dy, x, y, d0, d1;
	bool gg;
	scanf("%lf%lf%lf%lf", &gx, &gy, &dx, &dy);
	gg = false;
	while (scanf("%lf%lf", &x, &y) == 2)
	{
		d0 = getdis(gx-x, gy-y);
		d1 = getdis(dx-x, dy-y);
		if (d0*4 <= d1)
		{
			printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", x, y);
			gg = true;
			break;
		}
	}
	if (!gg)
	{
		puts("The gopher cannot escape.");
	}
	return 0;
}
