#include <stdio.h>
#include <math.h>

int main()
{
	int cas, n, m;
	double a, b, c, at, x, pi;
	cas = 0;
	pi = acos(-1);
	while(scanf("%d : %d", &n, &m) == 2)
	{
		at = atan((double)m/n);
		a = 16.0*n*n-/*4.0*pi*pi**/n*n*16.0*at*at-/*4.0*pi*pi**/m*m*16.0*at*at;
		b = -3200.0 * n;
		c = 160000.0;
		x = (-b-sqrt(b*b-4.0*a*c))/(2.0*a);
		printf("Case %d: %.7lf %.7lf\n", ++cas, x*n*2, x*m*2);
	}
	return 0;
}
