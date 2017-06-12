#include <stdio.h>
#include <math.h>

int main()
{
	int l, f;
	double v;
	while(scanf("%d%d", &l, &f) == 2)
	{
		if(l == 0 && f == 0)
		{
			break;
		}
		v = sqrt(f * 2.0 * l);
		printf("%.8lf %.8lf\n", v, 3600.0/(l+v*v/(2.0*f))*v);
	}
	return 0;
}
