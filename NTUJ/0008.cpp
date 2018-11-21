#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, x;
	int c, d;
	while(scanf("%lf%lf%d%d", &a, &b, &c, &d) == 4)
	{
		if(a == 0.0 && b == 0.0 && c == 0 && d == 0)
		{
			break;
		}
		/*x = (-a*(c+d)+sqrt(a*a*(c+d)*(c+d)+4.0*c*d*a*b)) / (2.0*c*d);*/
		x = (-a+sqrt(a*a+4.0*c*d*a*b)) / (2.0*c*d);
		printf("%.3lf\n", -log10(c*x));
	}
	return 0;
}
