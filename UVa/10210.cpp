#include <stdio.h>
#include <math.h>

int main()
{
	double x1, x2, y1, y2, p, q, d, PI;
	PI = 2.0 * acos(0.0);
	while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &p, &q) == 6)
	{
		p = p * PI / 180.0;
		q = q * PI / 180.0;
		d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		printf("%.3lf\n", d/tan(p)+d/tan(q));
	}
	return 0;
}
