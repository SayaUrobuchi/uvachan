#include <stdio.h>
#include <math.h>

int main()
{
	int count;
	double a, b, c, d, p, q;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		p = b*c/(6*a*a) - (b*b*b)/(27*a*a*a) - d/2/a;
		q = c/3/a - (b*b)/(9*a*a);
		printf("%.3lf\n", -b/(a*3)
			+cbrt(p + sqrt(p*p + q*q*q))
			+cbrt(p - sqrt(p*p + q*q*q)));
	}
	return 0;
}
