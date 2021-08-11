#include <iostream>
#include <cmath>

const double PI = acos(-1);

int main()
{
	int k, w, h, i;
	double a;
	while (scanf("%d%d%d", &k, &w, &h) == 3)
	{
		a = 0.5;
		for (i=1; i<k; i++)
		{
			a += (1<<i);
		}
		a += (1<<(k-1));
		// wa * tan(t) = h
		// => h/(wa) = tan(t)
		printf("%.10lf\n", atan(h/(double)(a*w))*180/PI);
	}
	return 0;
}
