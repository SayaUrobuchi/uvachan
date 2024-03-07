#include <iostream>
#include <cmath>
#include <random>
using namespace std;

const int TEST_T = 3000;
const double PI = acos(-1);
const int N = 16;

int px[N], py[N], pr[N];
random_device rd;
mt19937_64 gen(rd());
uniform_real_distribution<> dist(0, 1);

bool in_circle(double x, double y, double cx, double cy, double cr)
{
	double dx = x - cx;
	double dy = y - cy;
	double d = dx*dx + dy*dy;
	return d <= cr*cr;
}

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	int max_x = -1e3, min_x = 1e3;
	int max_y = -1e3, min_y = 1e3;
	for (i=0; i<n; i++)
	{
		scanf("%d%d%d", &px[i], &py[i], &pr[i]);
		max_x = max(max_x, px[i]+pr[i]);
		max_y = max(max_y, py[i]+pr[i]);
		min_x = min(min_x, px[i]-pr[i]);
		min_y = min(min_y, py[i]-pr[i]);
	}
	int ans = 0;
	for (i=0; i<TEST_T; i++)
	{
		double x = min_x + (max_x-min_x) * 1. / TEST_T * i;
		for (j=0; j<TEST_T; j++)
		{
			double y = min_y + (max_y-min_y) * 1. / TEST_T * j;
			bool in_c = false;
			for (k=0; k<n&&!in_c; k++)
			{
				in_c = in_circle(x, y, px[k], py[k], pr[k]);
			}
			ans += in_c;
		}
	}
	printf("%.10lf\n", ans * (max_x-min_x) * 1. / TEST_T
						   * (max_y-min_y) * 1. / TEST_T);
	return 0;
}
