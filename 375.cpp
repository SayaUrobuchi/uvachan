#include <stdio.h>
#include <math.h>

int main()
{
	int count;
	double b, h, c, r, temp, temp2, sum, x, pi;
	pi = 2.0 * acos(0.0);
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lf%lf", &b, &h);
		b /= 2;
		x = sqrt(h*h + b*b);
		temp = x + b;
		temp2 = x - b;
		r = b * h / temp;
		temp2 /= temp;
		sum = 0;
		do
		{
			sum += r;
			r *= temp2;
		}while(r > 0.000001);
		c = sum * 2.0 * pi;
		printf("%13.6f\n", c);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
