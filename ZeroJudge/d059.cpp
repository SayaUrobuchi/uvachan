#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, d, e, f;
	while(scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) == 6)
	{
		printf("%.0lf\n%.3lf\n%d\n%d\n", pow(a, b), sqrt(c), d>0?d:-d, e);
	}
	return 0;
}
