#include <stdio.h>
#include <math.h>

double ab(double t)
{
	return t<0 ? -t : t;
}

int main()
{
	double x1, x2, x3, x4, y1, y2, y3, y4, v1, v2, rat, mx, my;
	while(scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) == 4)
	{
		v1 = x2-x1;
		v2 = y2-y1;
		rat = sqrt(3) / 2.0;
		mx = (x2+x1)/2;
		my = (y2+y1)/2;
		x3 = v2*rat + mx;
		y3 = -v1*rat + my;
		x4 = -v2*rat + mx;
		y4 = v1*rat + my;
		if(x3 < x4 || (ab(x3-x4) < 1e-8 && y3 < y4))
		{
			printf("%.3lf %.3lf %.3lf %.3lf\n", x3, y3, x4, y4);
		}
		else
		{
			printf("%.3lf %.3lf %.3lf %.3lf\n", x4, y4, x3, y3);
		}
	}
	return 0;
}
