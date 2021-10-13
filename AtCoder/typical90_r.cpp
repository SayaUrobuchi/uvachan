#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

int main()
{
	int t, d, x, y, m, i, u;
	double ang, tx, ty, tz, ans;
	while (scanf("%d", &t) == 1)
	{
		scanf("%d%d%d%d", &d, &x, &y, &m);
		for (i=0; i<m; i++)
		{
			scanf("%d", &u);
			u %= t;
			ang = (u - t/2.0) / t * PI * 2;
			ty = sin(ang) * d / 2.0;
			tz = d / 2.0 + cos(ang) * d / 2.0;
			tx = sqrt(x*1.0*x+(y-ty)*(y-ty));
			ans = atan2(tz, tx);
			printf("%.10lf\n", ans*180.0/PI);
		}
	}
	return 0;
}
