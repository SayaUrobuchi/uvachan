#include <stdio.h>
#include <math.h>

const double PI = acos(-1);

int main()
{
	double r, x, y, dis, ang, a, b;
	while (scanf("%lf%lf%lf", &r, &x, &y) == 3)
	{
		dis = sqrt(x*x+y*y);
		if (dis > r)
		{
			puts("miss");
			continue;
		}
		ang = acos(dis/r);
		a = dis * r*sin(ang) + (r*r*(PI-ang));
		b = r*r*PI - a;
		printf("%.10lf %.10lf\n", a, b);
	}
	return 0;
}
