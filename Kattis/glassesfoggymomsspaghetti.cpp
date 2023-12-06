#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double d, x, y, h;
	scanf("%lf%lf%lf%lf", &d, &x, &y, &h);
	double a = atan2(y+h/2, x);
	double b = atan2(y, x);
	double c = atan2(y-h/2, x);
	double ans = tan(b-c) * d;
	ans += tan(a-b) * d;
	printf("%.10lf\n", ans);
	return 0;
}
