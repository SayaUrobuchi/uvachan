#include <iostream>
#include <cmath>

const double PI = acos(-1);
const double EPS = 1e-8;

int main()
{
	int n, i, a, b, c;
	double len, x0, x1, y0, y1, p, q, mid, d, t, v;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, len=0; i<n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (a < b)
			{
				std::swap(a, b);
			}
			x0 = a;
			y0 = 0;
			for (p=0, q=PI; q-p>EPS; )
			{
				mid = (p+q) / 2;
				x1 = c * cos(mid);
				y1 = c * sin(mid);
				d = (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0);
				if (b*b <= d)
				{
					q = mid;
				}
				else
				{
					p = mid;
				}
			}
			t = (p+q) / 2;
			//printf("t: %.10lf\n", t/PI*180);
			for (p=0, q=PI/2-t; q-p>EPS; )
			{
				mid = (p+q) / 2;
				v = c / 2.0 * cos((PI/2) - t - mid);
				if (v <= a*sin(mid))
				{
					q = mid;
				}
				else
				{
					p = mid;
				}
			}
			//printf("!? %.10lf %.10lf, ang: %.10lf\n", sin((p+q)/2), a * sin((p+q)/2) * 2, (p+q)/2/PI*180);
			len += a * sin((p+q)/2) * 2;
		}
		printf("%.10lf\n", len);
	}
	return 0;
}
