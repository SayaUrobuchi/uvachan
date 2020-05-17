#include <stdio.h>

int main()
{
	double n;
	while (scanf("%lf", &n) == 1)
	{
		printf("%.0lf\n", n*1000*5280/4854);
	}
	return 0;
}
