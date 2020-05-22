#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	double n;
	while (scanf("%lf", &n) == 1)
	{
		printf("%.10lf\n", pow(n, 1.0/n));
	}
	return 0;
}