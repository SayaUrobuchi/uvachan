#include <stdio.h>
#include <math.h>

int main()
{
	int count;
	double a, b, c, r, t, u, v, w, x, y, z, area;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf", &r, &u, &v, &w, &x, &y, &z);
		a = u;
		b = v;
		c = x/w*v;
		t = r * sqrt((a+b+c)/(a*b*c));
		area = (a+b+c)*t*r;
		printf("%.4lf\n", area);
	}
	return 0;
}
