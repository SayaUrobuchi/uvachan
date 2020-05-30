#include <stdio.h>
#include <math.h>

int main()
{
	double x1, x2, y1, y2, p;
	while (scanf("%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &p) == 5)
	{
		if (x1 == 0.0)
		{
			break;
		}
		printf("%.10lf\n", pow(pow(fabs(x1-x2), p) + pow(fabs(y1-y2), p), 1.0/p));
	}
	return 0;
}
