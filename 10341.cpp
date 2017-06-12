#include <stdio.h>
#include <math.h>

int p, q, r, s, t, u;

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
	return ab(now) < 0.00000001;
}

double bisearch(double left, double right)
{
	double center, temp;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	if(zero(temp=(p*exp(-center) + q*sin(center) + r*cos(center) + s*tan(center) + t*center*center + u)))
	{
		return center;
	}
	else if(temp > 0)
	{
		return bisearch(center+0.00000000001, right);
	}
	return bisearch(left, center-0.00000000001);
}

int main()
{
	double temp;
	while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) == 6)
	{
		temp = bisearch(0.0, 1.0);
		if(temp == -1)
		{
			printf("No solution\n");
		}
		else
		{
			printf("%.4f\n", temp);
		}
	}
	return 0;
}
