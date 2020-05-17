#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, d;
	double s;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		s = (a+b+c+d)/2.;
		printf("%.10lf\n", sqrt((s-a)*(s-b)*(s-c)*(s-d)));
	}
	return 0;
}