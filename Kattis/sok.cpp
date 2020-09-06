#include <stdio.h>

int main()
{
	int a, b, c, d, e, f;
	double res;
	while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) == 6)
	{
		if (a*e <= b*d && a*f <= c*d)
		{
			res = (double)a/d;
		}
		else if (b*d <= a*e && b*f <= c*e)
		{
			res = (double)b/e;
		}
		else
		{
			res = (double)c/f;
		}
		printf("%.10lf %.10lf %.10lf\n", a-d*res, b-e*res, c-f*res);
	}
	return 0;
}
