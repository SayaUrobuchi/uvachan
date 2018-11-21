#include <stdio.h>
#include <math.h>

double a, b, c;

double ab(double now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int zero(double now)
{
	return ab(now) < 0.000000001;
}

double bisearch(double left, double right)
{
	double center, temp, temp2;
	center = left + right;
	center /= 2;
	temp = center * center;
	if(zero(temp2=(c - (1.0/sqrt(b*b-temp) + 1.0/sqrt(a*a-temp)))))
	{
		return center;
	}
	else if(temp2 > 0)
	{
		return bisearch(center+0.00000000001, right);
	}
	return bisearch(left, center-0.00000000001);
}

int main()
{
	while(scanf("%lf%lf%lf", &a, &b, &c) == 3)
	{
		c = 1.0 / c;
		printf("%.3lf\n", bisearch(0.0, a));
	}
	return 0;
}
