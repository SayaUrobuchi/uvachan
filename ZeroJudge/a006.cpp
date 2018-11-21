#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	double d;
	while(scanf("%d%d%d", &a, &b, &c) == 3)
	{
		d = b*b - 4*a*c;
		if(!d)
		{
			printf("Two same roots x=%g\n", (-b)/(2.0*a));
		}
		else if(d > 0)
		{
			d = sqrt(d);
			printf("Two different roots x1=%g , x2=%g\n", ((-b)+d)/(2.0*a), ((-b)-d)/(2.0*a));
		}
		else
		{
			printf("No real root\n");
		}
	}
	return 0;
}
