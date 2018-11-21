#include <stdio.h>
#include <math.h>

int main()
{
	double x, y, z, sum, a;
	while(scanf("%lf%lf%lf", &x, &y, &z) == 3)
	{
		sum = x + y + z;
		if(!sum)
		{
			printf("The radius of the round table is: 0.000\n");
			continue;
		}
		sum /= 2;
		a = sum * (sum - x) * (sum - y) * (sum - z);
		a = sqrt(a);
		a /= sum;
		printf("The radius of the round table is: %.3f\n", a);
	}
	return 0;
}
