#include <iostream>
#include <cmath>

const double PI = acos(-1);
const double RATE = 1e3;

int n;
double pr[16384], px[16384], py[16384], pz[16384];

double spherev(double r)
{
	return 4.0/3.0*PI*r*r*r;
}

double spherec(double r, double h)
{
	return PI*h*h/3.0*(3*r-h);
}

double spherecut(double cut, double r, double x, double y, double z)
{
	if (cut <= z-r)
	{
		return 0.0;
	}
	if (cut >= z+r)
	{
		return spherev(r);
	}
	if (cut < z)
	{
		return spherec(r, cut-(z-r));
	}
	return spherev(r) - spherec(r, (z+r)-cut);
}

double calc(double cut)
{
	int i;
	double res;
	res = cut * 1e4;
	for (i=0; i<n; i++)
	{
		res -= spherecut(cut, pr[i], px[i], py[i], pz[i]);
	}
	return res;
}

int main()
{
	int m, i;
	double v, one, last, p, q, mid, f;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, v=1e6; i<n; i++)
		{
			scanf("%lf%lf%lf%lf", &pr[i], &px[i], &py[i], &pz[i]);
			pr[i] /= RATE;
			px[i] /= RATE;
			py[i] /= RATE;
			pz[i] /= RATE;
			v -= spherev(pr[i]);
		}
		one = v / m;
		for (i=0, last=0, v=0; i<m; i++)
		{
			for (p=last, q=100.1; q-p>1e-7; )
			{
				mid = (p+q) / 2.0;
				f = calc(mid);
				if (f-v < one)
				{
					p = mid;
				}
				else
				{
					q = mid;
				}
			}
			mid = (p+q) / 2.0;
			v = calc(mid);
			printf("%.10lf\n", mid-last);
			last = mid;
		}
	}
	return 0;
}
