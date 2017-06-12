#include <stdio.h>
#include <math.h>

int main()
{
	double x1, x2, x3, y1, y2, y3, delta, a1, a2, b1, b2, c1, c2, a, b, c, i, j, k;
	while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6)
	{
		a1 = x1 - x2;
		a2 = x2 - x3;
		b1 = y1 - y2;
		b2 = y2 - y3;
		c1 = x1 * x1 + y1 * y1;
		c2 = x2 * x2 + y2 * y2;
		c1 -= c2;
		c2 -= x3 * x3 + y3 * y3;
		delta = a1 * b2 - a2 * b1;
		a = c1 * b2 - c2 * b1;
		a /= delta;
		b = a1 * c2 - a2 * c1;
		b /= delta;
		c = x1 * x1 + y1 * y1 - x1 * a - y1 * b;
		c = -c;
		i = a / 2;
		j = b / 2;
		k = (x1 - i) * (x1 - i) + (y1 - j) * (y1 - j);
		k = sqrt(k);
		if(i < 0)
		{
			printf("(x + %.3f)^2 + ", -i);
		}
		else
		{
			printf("(x - %.3f)^2 + ", i);
		}
		if(j < 0)
		{
			printf("(y + %.3f)^2 = ", -j);
		}
		else
		{
			printf("(y - %.3f)^2 = ", j);
		}
		printf("%.3f^2\n", k);
		if(a < 0)
		{
			printf("x^2 + y^2 + %.3fx", -a);
		}
		else
		{
			printf("x^2 + y^2 - %.3fx", a);
		}
		if(b < 0)
		{
			printf(" + %.3fy", -b);
		}
		else
		{
			printf(" - %.3fy", b);
		}
		if(c < 0)
		{
			printf(" - %.3f = 0\n\n", -c);
		}
		else
		{
			printf(" + %.3f = 0\n\n", c);
		}
	}
	return 0;
}