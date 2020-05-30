#include <stdio.h>
#include <math.h>
#include <algorithm>

int main()
{
	int count, x, y;
	double a, b, c, h;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &x, &y);
		a = 12;
		b = -4*(x+y);
		c = x*y;
		h = (-b-sqrt(b*b-4*a*c))/(2*a);
		printf("%.10lf\n", h*(x-h-h)*(y-h-h));
	}
	return 0;
}
