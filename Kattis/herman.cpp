#include <stdio.h>
#include <math.h>

const double PI = acos(-1);

int main()
{
	int r;
	while (scanf("%d", &r) == 1)
	{
		printf("%.10lf\n%d\n", r*r*PI, (r*r)<<1);
	}
	return 0;
}
