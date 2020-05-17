#include <stdio.h>
#include <math.h>

const double PI = acos(-1);
const double EPS = 1e-8;

int main()
{
	int n, m;
	double p, q, area, r, a, b, got, h;
	// (b^2*pi*1/3 - (a^2*pi*1/3*a/b)) * h
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		area = (n*n/4.0)*PI*n;
		int c = 0;
		for (p=0, q=n; p<q; )
		{
			r = (p+q) / 2;
			got = area - (r*r/4.0)*PI*r;
			b = n/2.0;
			a = r/2.0;
			h = (n-r)*b/(b-a);
			got -= (b*b*PI/3 - (a*a*PI/3*a/b)) * h;
			if (fabs(got-m) < EPS)
			{
				break;
			}
			else if (got > m)
			{
				p = r;
			}
			else
			{
				q = r;
			}
		}
		printf("%.10lf\n", r);
	}
	return 0;
}
