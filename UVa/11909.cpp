#include <stdio.h>
#include <math.h>

const double pi = acos(-1);

int main()
{
	int l, w, h, t;
	double ang, ans;
	while(scanf("%d%d%d%d", &l, &w, &h, &t) == 4)
	{
		ang = t*pi/180.0;
		if(tan(ang)*l < h)
		{
			ans = (h*l-l*l*tan(ang)/2)*w;
		}
		else
		{
			ang = pi/2-ang;
			ans = (h*h*tan(ang)/2)*w;
		}
		printf("%.3lf mL\n", ans);
	}
	return 0;
}
