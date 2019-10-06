#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, d;
	while (scanf("%lf%lf%lf%lf", &a, &b, &c, &d) == 4)
	{
		puts(fabs(a*d-b*c)<1e-7?"0":"1");
	}
	return 0;
}
