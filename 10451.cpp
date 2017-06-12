#include <stdio.h>
#include <math.h>

int main()
{
	int cas, n;
	double pi, a, inc, ouc, tmp, calc, b;
	cas = 0;
	pi = 2.0 * acos(0.0);
	while(scanf("%d%lf", &n, &a) == 2)
	{
		if(n < 3)
		{
			break;
		}
		calc = a / n;
		b = pi / n;
		inc = calc / tan(b);
		ouc = sqrt(inc) / cos(b);
		printf("Case %d: %.5f %.5f\n", ++cas, ouc*ouc*pi-a, a-inc*pi);
	}
	return 0;
}
