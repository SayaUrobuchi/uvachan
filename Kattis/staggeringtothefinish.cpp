#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

int main()
{
	int n, i, j;
	double r, s, w, f, l[2], d;
	scanf("%d%lf%lf%lf%lf%lf%lf", &n, &r, &s, &w, &f, &l[0], &l[1]);
	while (scanf("%lf", &d) == 1)
	{
		double dd = d;
		printf("%.3lf", dd);
		for (i=0; i<n; i++)
		{
			d = dd;
			double x, y;
			for (j=0; ; j++)
			{
				if (j & 1)
				{
					double pr = (r + i*w);
					double rr = pr + l[i>0];
					double len = rr * PI;
					if (d > len)
					{
						d -= len;
						continue;
					}
					double rat = d / len;
					double ang = rat * PI + (j/2) * PI;
					ang = -(PI/2) - ang;
					if ((j/2) & 1)
					{
						x = s / 2;
					}
					else
					{
						x = -s / 2;
					}
					x += cos(ang) * pr;
					y = sin(ang) * pr;
					break;
				}
				else
				{
					double len = (j==0?f:s/2) + s/2;
					if (d > len)
					{
						d -= len;
						continue;
					}
					if ((j/2) & 1)
					{
						x = -s / 2 + d;
						y = r + i*w;
					}
					else
					{
						x = (j==0?f:s/2) - d;
						y = -(r + i*w);
					}
					break;
				}
			}
			printf(" %.4lf %.4lf", x, y);
		}
		puts("");
	}
	return 0;
}
