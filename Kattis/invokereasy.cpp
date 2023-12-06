#include <iostream>
using namespace std;

int main()
{
	double a, b, c, d;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	// (cR + dI) * (xR + yI) = 1R + 0I
	// cxR + dxI + cyI - dyR = 1R + 0I
	// (cx - dy)R + (dx + cy)I = 1R + 0I
	// ========
	// 1) cx - dy = 1
	// 2) dx + cy = 0
	// ========
	// 1) cdx - ddy = d
	// 2) cdx + ccy = 0
	// ========
	// (cc + dd)y = -d
	// y = -d / (cc + dd)
	// x = -cy / d
	// x = cd / (cc + dd) / d
	// x = c / (cc + dd)
	double y = -d / (c*c + d*d);
	double x = c / (c*c + d*d);
	double na = a * x - b * y;
	double nb = b * x + a * y;
	printf("%.10lf %.10lf\n", na, nb);
	return 0;
}
