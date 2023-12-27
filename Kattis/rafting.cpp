#include <iostream>
#include <cmath>
using namespace std;

const int N = 105;

int pn[2], px[2][N], py[2][N];

double cross(double x0, double y0, double x1, double y1)
{
	return x0*y1 - x1*y0;
}

double get_dis(double x0, double y0, double x1, double y1)
{
	return sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
}

double ptos(int a, int b)
{
	int i, j;
	double ret = get_dis(px[0][a], py[0][a], px[1][b], py[1][b]);
	for (i=0, j=1; i<2; i++, j--, swap(a, b))
	{
		double dx = px[j][b+1] - px[j][b];
		double dy = py[j][b+1] - py[j][b];
		swap(dx, dy);
		dy = -dy;
		if (cross(dx, dy, px[j][b]-px[i][a], py[j][b]-py[i][a])
		  * cross(dx, dy, px[j][b+1]-px[i][a], py[j][b+1]-py[i][a]) < 0)
		{
			double itoj0 = get_dis(px[i][a], py[i][a], px[j][b], py[j][b]);
			double itoj1 = get_dis(px[i][a], py[i][a], px[j][b+1], py[j][b+1]);
			double jtoj = get_dis(px[j][b+1], py[j][b+1], px[j][b], py[j][b]);
			double s = (itoj0 + itoj1 + jtoj) / 2;
			double area = sqrt(s*(s-itoj0)*(s-itoj1)*(s-jtoj));
			double height = area * 2 / jtoj;
			ret = min(ret, height);
		}
	}
	return ret;
}

int main()
{
	int count, i, j;
	double ans;
	scanf("%d", &count);
	while (count--)
	{
		for (i=0; i<2; i++)
		{
			scanf("%d", &pn[i]);
			for (j=0; j<pn[i]; j++)
			{
				scanf("%d%d", &px[i][j], &py[i][j]);
			}
			px[i][j] = px[i][0];
			py[i][j] = py[i][0];
		}
		for (i=0, ans=1e100; i<pn[0]; i++)
		{
			for (j=0; j<pn[1]; j++)
			{
				ans = min(ans, ptos(i, j));
			}
		}
		printf("%.10lf\n", ans/2);
	}
	return 0;
}
