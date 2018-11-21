#include <stdio.h>
#include <math.h>

int main()
{
	double n;
	int m;
	while(scanf("%lf", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		m = (int)(pow(n, 1.0/3.0)+0.0000001);
		n -= m*m*m;
		printf("%.4f\n", m+n/(3*(m*m)));
	}
	return 0;
}
