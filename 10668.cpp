#include <stdio.h>
#include <math.h>

#define EPS 1e-10
#define SHIFT 1e-15

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
	return now < EPS;
}

int main()
{
	double l, n, c, r, pi, now, left, right, center, theta, temp;
	pi = 2.0 * acos(0.0);
	while(scanf("%lf%lf%lf", &l, &n, &c) == 3)
	{
		if(l < 0 && n < 0 && c < 0)
		{
			break;
		}
		now = l * (1.0+n*c);
		/*printf("%.3lf\n", now);*/
		for(left=SHIFT, right=pi; left<right||!zero(right-left); )
		{
			center = left + right;
			center /= 2.0;
			theta = center;
			r = now / theta;
			/*printf("%.3lf %.3lf\n", r, theta);*/
			temp = r * sin(theta/2.0) * 2.0;
			/*printf("%.3lf\n", temp);*/
			if(zero(ab(l-temp)))
			{
				break;
			}
			else if(l < temp)
			{
				left = center + SHIFT;
			}
			else
			{
				right = center - SHIFT;
			}
		}
		printf("%.3lf\n", r-r*cos(theta/2.0));
	}
	return 0;
}
