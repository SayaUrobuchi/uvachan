#include <stdio.h>
#include <math.h>

int main()
{
	int br, s;
	double pi, a, r, i, e;
	pi = 2.0 * acos(0.0);
	while(scanf("%d%d", &br, &s) == 2)
	{
		if(s == 1)
		{
			printf("%.10lf %.10lf %.10lf\n", (double)br, 0.0, 0.0);
		}
		else if(s == 2)
		{
			printf("%.10lf %.10lf %.10lf\n", br/2.0, 0.0, br*br*pi/2.0);
		}
		else
		{
			a = pi / s;
			r = br - br / (1+sin(a));
			i = r * r / tan(a) * s - r * r * (pi / 2 - a) * s;
			e = br * br * pi - i - r * r * pi * s;
			printf("%.10lf %.10lf %.10lf\n", r, i, e);
		}
	}
	return 0;
}

