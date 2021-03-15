#include <iostream>
#include <cmath>

const double PI = acos(-1);
int n, m;
double r;

double getdis(int x0, int y0, int x1, int y1)
{
	return abs(y0-y1)*r/m + std::min(y0, y1)*r/m*PI*abs(x1-x0)/n;
}

int main()
{
	int i, t, x0, x1, y0, y1;
	double ans, d;
	while (scanf("%d%d%lf", &n, &m, &r) == 3)
	{
		scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
		ans = getdis(x0, y0, x1, y1);
		t = std::min(y0, y1);
		for (i=0; i<t; i++)
		{
			d = getdis(x0, y0, x0, i) + getdis(x0, i, x1, i) + getdis(x1, i, x1, y1);
			ans = std::min(ans, d);
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
