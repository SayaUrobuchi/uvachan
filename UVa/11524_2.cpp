#include <stdio.h>
#include <math.h>

int main()
{
	int count;
	double a, b, c, n1, n2, n3, m1, m2, m3, t, area, r;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf", &r, &m1, &n1, &m2, &n2, &m3, &n3);
		a = m1*m2;
		b = n1*m2;
		c = n2*n1;
		t = a+b+c;
		area = t*t*r*r/sqrt(t*c*b*a);
		printf("%.4lf\n", area);
	}
	return 0;
}
