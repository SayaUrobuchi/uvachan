#include <stdio.h>
#include <math.h>

int main()
{
	double i, j, k, sum, temp;
	while(scanf("%lf%lf%lf", &i, &j, &k) == 3)
	{
		sum = i + j + k;
		sum /= 2;
		temp = sum * (sum-i) * (sum-j) * (sum-k);
		if(temp > 0)
		{
			printf("%.3f\n", 4.0 / 3 * sqrt(temp));
		}
		else
		{
			printf("-1.000\n");
		}
	}
	return 0;
}
