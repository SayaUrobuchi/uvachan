#include <iostream>
#include <cmath>

const double PI = acos(-1);
const double P2 = PI*2;

double high[16], low[16];

int main()
{
	int n, i, j, x, y, p, ans;
	double ang, d, c, dis, best;
	while (scanf("%d", &n) == 1)
	{
		for (i=3; i<=8; i++)
		{
			low[i] = 1e20;
			high[i] = 0;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &x, &y);
			for (j=3; j<=8; j++)
			{
				ang = atan2(y, x);
				if (ang < 0)
				{
					ang += P2;
				}
				p = (int)(floor(ang/(P2/j))+1e-9);
				if (fabs(cos(P2/j*(p+1))-cos(P2/j*p)) < 1e-6)
				{
					dis = fabs(x);
				}
				else
				{
					d = (sin(P2/j*(p+1))-sin(P2/j*p)) / (cos(P2/j*(p+1))-cos(P2/j*p));
					//printf("....dd %.10lf\n", d);
					c = y - d*x;
					dis = fabs(c) / sqrt(d*d+1);
				}
				if (dis < low[j])
				{
					low[j] = dis;
				}
				if (dis > high[j])
				{
					high[j] = dis;
				}
			}
		}
		for (i=3, best=0; i<=8; i++)
		{
			//printf("... %.10lf %.10lf\n", low[i], high[i]);
			if (low[i]*low[i]/(high[i]*high[i]) > best)
			{
				best = low[i]*low[i]/(high[i]*high[i]);
				ans = i;
			}
		}
		printf("%d %.10lf\n", ans, best);
	}
	return 0;
}
