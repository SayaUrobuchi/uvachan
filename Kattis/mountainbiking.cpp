#include <iostream>
#include <cmath>

const double PI = acos(-1);

int dis[128], ang[128];

int main()
{
	int n, i, j;
	double g, t, a, v;
	while (scanf("%d%lf", &n, &g) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &dis[i], &ang[i]);
		}
		for (i=0; i<n; i++)
		{
			for (j=i, v=0; j<n; j++)
			{
				a = g * cos(ang[j]/180.0*PI);
				t = (-v+sqrt(v*v+2*a*dis[j]))/a;
				v += a*t;
			}
			printf("%.10lf\n", v);
		}
	}
	return 0;
}
