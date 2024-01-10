#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a;
	scanf("%lf", &a);
	const double PI = acos(-1);
	double fix = PI / 2;
	double st = max(0.0, a-PI);
	double ed = st + PI * 2;
	double best = 1e9;
	for (double t=st; t<=ed; t+=1e-5)
	{
		double x0 = cos(fix+t);
		double y0 = sin(fix+t) + 1;
		double z0 = t * 2;
		double x1 = cos(fix+a+t);
		double y1 = sin(fix+a+t);
		double z1 = a + t;
		//printf("%.6lf %.6lf\n", x0, y0);
		//printf("%.6lf %.6lf\n", x1, y1);
		double dx = x0 - x1;
		double dy = y0 - y1;
		double dz = z0 - z1;
		//printf("%.6lf %.6lf\n", dx*dx, dy*dy);
		double ans = sqrt(dx*dx + dy*dy + dz*dz);
		best = min(best, ans);
	}
	printf("%.10lf\n", best);
	return 0;
}
