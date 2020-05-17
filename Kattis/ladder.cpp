#include <stdio.h>
#include <math.h>

const double PI = acos(-1);

int main()
{
	int n, m;
	double a;
	while (scanf("%d%d", &n, &m) == 2)
	{
		a = (m*PI) / 180;
		printf("%.0lf\n", ceil(n/sin(a)));
	}
	return 0;
}
