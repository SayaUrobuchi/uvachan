#include <stdio.h>
#include <math.h>

int main()
{
	int d, v;
	double pi, ans;
	pi = 2.0 * acos(0.0);
	while(scanf("%d%d", &d, &v) == 2)
	{
		if(!d && !v)
		{
			break;
		}
		ans = d * d * d - 6 * v / pi;
		ans = pow(ans, 1.0/3.0);
		printf("%.3f\n", ans);
	}
	return 0;
}
