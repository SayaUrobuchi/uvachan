#include <iostream>
#include <cmath>
using namespace std;

double px[32], py[32];

double cross(int a, int b, int c)
{
	double x0 = px[b]-px[a];
	double y0 = py[b]-py[a];
	double x1 = px[c]-px[b];
	double y1 = py[c]-py[b];
	return x0*y1 - y0*x1;
}

double getdis(int a, int b)
{
	double dx = px[a]-px[b];
	double dy = py[a]-py[b];
	return sqrt(dx*dx+dy*dy);
}

int main()
{
	int n, i, j;
	double t, best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%lf%lf", &px[i], &py[i]);
		}
		px[n] = px[0];
		py[n] = py[0];
		for (i=0, j=2, best=1e100; i<n; i++)
		{
			for (; fabs(cross(i, i+1, j))<fabs(cross(i, i+1, j+1)); j=(j+1)%n);
			t = fabs(cross(i, i+1, j)) / getdis(i, i+1);
			//printf(".. %.10lf %.10lf\n", fabs(cross(i, i+1, j)), getdis(i, i+1));
			if (t < best)
			{
				best = t;
			}
		}
		printf("%.10lf\n", best);
	}
	return 0;
}
