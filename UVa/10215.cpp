#include <stdio.h>
#include <math.h>

int main()
{
	double n, m, temp;
	while(scanf("%lf%lf", &n, &m) == 2)
	{
		if(n < m)
		{
			temp = n;
			n = m;
			m = temp;
		}
		printf("%.3f 0.000 %.3f\n", (n+m-sqrt(n*n-n*m+m*m))/6.0+0.0000001, m/2.0+0.0000001);
	}
	return 0;
}
