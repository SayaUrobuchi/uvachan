#include <iostream>

int main()
{
	int cas, i, c;
	double a, b, x, y, nx, ny;
	cas = 0;
	while (scanf("%lf%lf%d", &a, &b, &c) == 3)
	{
		for (x=0, y=0, i=0; i<c&&x*x+y*y<=4; i++)
		{
			nx = x*x-y*y+a;
			ny = 2*x*y+b;
			x = nx;
			y = ny;
		}
		printf("Case %d: ", ++cas);
		if (x*x + y*y > 4)
		{
			puts("OUT");
		}
		else
		{
			puts("IN");
		}
	}
	return 0;
}
