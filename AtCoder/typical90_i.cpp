#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = acos(-1);
const double PI2 = PI + PI;

int center;
int px[2048], py[2048];
double pp[2048];

int main()
{
	int n, i, j, k;
	double t, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		for (i=0, ans=0, --n; i<=n; i++)
		{
			for (j=0, k=0; j<=n; j++)
			{
				if (j != i)
				{
					pp[k++] = atan2(py[j]-py[i], px[j]-px[i]) + PI;
				}
			}
			sort(pp, pp+n);
			for (j=0; j<n; j++)
			{
				t = pp[j] + PI;
				if (t >= PI2)
				{
					t -= PI2;
				}
				k = upper_bound(pp, pp+n, t) - pp;
				k %= n;
				ans = max(ans, min(fabs(pp[j]-pp[k]), PI2-fabs(pp[j]-pp[k])));
				//if (i == 2) printf(".. %.10lf %.10lf\n", pp[j]*180/PI, pp[k]*180/PI);
				k = (k+n-1)%n;
				ans = max(ans, min(fabs(pp[j]-pp[k]), PI2-fabs(pp[j]-pp[k])));
			}
		}
		printf("%.10lf\n", ans * 180 / PI);
	}
	return 0;
}
