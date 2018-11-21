#include <stdio.h>
#include <math.h>

int main()
{
	int n, count;
	double pi = acos(-1);
	double a, c;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		a = n * n * 6 / 10.0;
		c = (n/5.0);
		c = c*c * pi;
		printf("%.2f %.2f\n", c, a-c);
	}
	return 0;
}
