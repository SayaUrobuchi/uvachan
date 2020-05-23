#include <stdio.h>
#include <math.h>

const double PI = acos(-1);

int main()
{
	int count, a, b, c, d;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%.10lf\n", a*b*b/4.0/tan(PI/a)+(double)c*d*b*a+(double)c*d*c*d*PI);
	}
	return 0;
}
