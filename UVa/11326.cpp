#include <stdio.h>
#include <math.h>

int main()
{
	int count, temp, l, w, angle;
	double pi, theta, unit, route, height;
	pi = 2.0 * acos(0.0);
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &l, &w, &angle);
		if(angle == 0)
		{
			printf("1.000\n");
		}
		else
		{
			theta = pi * angle / 180.0;
			route = l / cos(theta);
			unit = w + w;
			temp = (int)(route * sin(theta) / unit);
			height = route * sin(theta) - unit * temp;
			if(height > w)
			{
				height = w + w - height;
			}
			printf("%.3lf\n", route/sqrt(l*l+height*height));
		}
	}
	return 0;
}
