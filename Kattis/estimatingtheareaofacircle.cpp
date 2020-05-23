#include <stdio.h>
#include <math.h>

const double PI = acos(-1);

int main()
{
	int n, m;
	double r;
	while (scanf("%lf%d%d", &r, &n, &m) == 3)
	{
		if (n == 0 && m == 0 && fabs(r) < 1e-6)
		{
			break;
		}
		printf("%.10lf %.10lf\n", r*r*PI, r*r*4*m/n);
	}
	return 0;
}
