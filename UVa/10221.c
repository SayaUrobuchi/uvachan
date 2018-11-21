#include <stdio.h>
#include <math.h>

double getdis(double x, double y)
{
	return sqrt(x*x+y*y);
}

int main()
{
	int r, s, a;
	double pi, ans, ang, x, y, ans1, ans2;
	char type[10];
	pi = 2.0 * acos(0.0);
	r = 6440;
	while(scanf("%d%d%s", &s, &a, type) == 3)
	{
		s += r;
		ang = a;
		if(*type == 'm')
		{
			ang /= 60.0;
		}
		ang -= (int)(ang/360.0+1e-10) * 360.0;
		if(ang >= 180.0)
		{
			ang = 360.0 - ang;
		}
		ang = ang / 180.0 * pi;
		x = s * cos(ang);
		y = s * sin(ang);
		ans1 = s * ang;
		ans2 = getdis(x-s, y);
		printf("%.6lf %.6lf\n", ans1, ans2);
	}
	return 0;
}

