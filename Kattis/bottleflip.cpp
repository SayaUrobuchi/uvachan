#include <iostream>
using namespace std;

const int RETRY = 1000;

double calc(double x, double h, double rd, double da, double dw)
{
	return x/2 + h/2 * da*(h-x) / (da*(h-x)+dw*x);
}

int main()
{
	int h, rd, da, dw, i;
	double l, r;
	scanf("%d%d%d%d", &h, &rd, &da, &dw);
	for (l=0, r=h, i=0; i<RETRY; i++)
	{
		double a = l + (r-l) / 3;
		double b = r - (r-l) / 3;
		double ra = calc(a, h, rd, da, dw);
		double rb = calc(b, h, rd, da, dw);
		//printf(".. %.3lf %.3lf\n", ra, rb);
		if (ra < rb)
		{
			r = b;
		}
		else
		{
			l = a;
		}
	}
	printf("%.10lf\n", l);
	return 0;
}
