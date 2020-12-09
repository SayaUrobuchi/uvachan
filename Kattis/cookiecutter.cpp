#include <iostream>
#include <cmath>

double px[64], py[64], nx[64], ny[64];

int main()
{
	int n, i;
	double a, na, mx, my, rat;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, a=0; i<n; i++)
		{
			scanf("%lf%lf", &px[i], &py[i]);
			if (i)
			{
				a += px[i-1]*py[i] - px[i]*py[i-1];
			}
		}
		a += px[i-1]*py[0] - px[0]*py[i-1];
		a = fabs(a) / 2.0;
		scanf("%lf", &na);
		rat = sqrt(na/a);
		nx[0] = px[0];
		ny[0] = py[0];
		mx = nx[0];
		my = ny[0];
		for (i=1; i<n; i++)
		{
			nx[i] = nx[i-1] + (px[i]-px[i-1])*rat;
			ny[i] = ny[i-1] + (py[i]-py[i-1])*rat;
			mx = std::min(mx, nx[i]);
			my = std::min(my, ny[i]);
		}
		for (i=0; i<n; i++)
		{
			printf("%.10lf %.10lf\n", nx[i]-mx, ny[i]-my);
		}
	}
	return 0;
}
