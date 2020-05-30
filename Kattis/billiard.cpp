#include <stdio.h>
#include <math.h>

const double PI = acos(-1);

int main()
{
	int a, b, c, d, e;
	long long p, q;
	double ang, t;
	while (scanf("%d%d%d%d%d", &a, &b, &c, &d, &e) == 5)
	{
		if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
		{
			break;
		}
		p = a*d;
		q = b*e;
		ang = atan2(q, p);
		t = sqrt(p*p+q*q) / c;
		printf("%.2lf %.2lf\n", ang/PI*180, t);
	}
	return 0;
}
