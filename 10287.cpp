#include <stdio.h>
#include <math.h>

int main()
{
	double n;
	double sq3, sq7;
	sq3 = sqrt(3.0);
	sq7 = sqrt(7.0);
	while(scanf("%lf", &n) == 1)
	{
		printf("%.10lf %.10lf %.10lf %.10lf\n", (n*0.5)*sq3, (n*sq3)/(2.0+sq3), (n*sq3)/4.0, ((n*7.0)/2.0)/(7.0/sq3+2.0*sq7));
	}
	return 0;
}
