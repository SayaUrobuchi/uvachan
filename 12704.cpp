#include <stdio.h>
#include <math.h>

int main()
{
	int count, p, q, r;
	double d;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &p, &q, &r);
		d = sqrt((p*p)+(q*q));
		printf("%.2f %.2f\n", r-d, r+d);
	}
	return 0;
}
