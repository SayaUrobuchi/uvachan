#include <stdio.h>
#include <math.h>

const double PI = acos(-1);

int main()
{
	int count;
	double v, ang, x, y, h0, h1, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%lf%lf%lf%lf%lf", &v, &ang, &x, &h0, &h1);
		ang = ang * PI / 180;
		// x = vtcos
		t = x / v / cos(ang);
		// y = vtsin - .5gtt
		y = v * t * sin(ang) - .5 * 9.81 * t * t;
		if (h1-1 > y && y > h0+1)
		{
			puts("Safe");
		}
		else
		{
			puts("Not Safe");
		}
	}
	return 0;
}
