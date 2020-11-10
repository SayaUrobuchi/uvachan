#include <iostream>
#include <cmath>

const double PI = acos(-1);

int main()
{
	int h, r, s;
	double ang, ans;
	while (scanf("%d%d%d", &r, &h, &s) == 3)
	{
		if (h == 0 && r == 0 && s == 0)
		{
			break;
		}
		ang = acos((double)r/h);
		//printf("%.10lf\n", ang*180.0/PI);
		ans = (2*PI-2*ang)*r;
		ans += h*sin(ang)*2;
		ans *= (100.0+s)/100.0;
		printf("%.2lf\n", ans);
	}
	return 0;
}
