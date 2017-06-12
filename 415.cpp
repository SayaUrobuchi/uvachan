#include <stdio.h>
#include <math.h>

int main()
{
	double pi, dis, lr, rr, len, alpha, beta, gamma, angle, range, sec;
	pi = 2.0 * acos(0.0);
	dis = 92900000.0;
	lr = 3950.0;
	rr = 432000.0;
	len = sqrt(dis*dis+rr*rr-lr*lr);
	alpha = atan(rr/dis) + atan(len/lr);
	angle = 2.0 * pi / 86400.0;
	while(scanf("%lf", &sec) == 1)
	{
		beta = alpha - sec * angle;
		/*printf("%.3lf\n", beta);*/
		range = dis * cos(beta) - lr;
		range /= sin(beta);
		if(range < -rr)
		{
			range = -rr;
		}
		if(range > rr)
		{
			range = rr;
		}
		gamma = asin(range/rr);
		/*printf("%.3lf\n", gamma);*/
		printf("%.3lf\n", 0.5+gamma/pi+cos(gamma)*range/(rr*pi)+1e-5);
	}
	return 0;
}
