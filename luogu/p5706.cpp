#include <stdio.h>

int main()
{
	double a;
	int b;
	scanf("%lf%d", &a, &b);
	printf("%.3lf\n%d\n", a/b, b<<1);
	return 0;
}
