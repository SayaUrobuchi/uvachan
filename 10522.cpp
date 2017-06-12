#include <stdio.h>
#include <math.h>

int main()
{
	int count;
	double aa, bb, cc, a, b, c, k;
	scanf("%d", &count);
	while(scanf("%lf%lf%lf", &aa, &bb, &cc) == 3)
	{
		if(aa < 1e-9 || bb < 1e-9 || cc < 1e-9)
		{
			printf("These are invalid inputs!\n");
			if(!--count)
			{
				break;
			}
			continue;
		}
		a = 1.0/aa;
		b = 1.0/bb;
		c = 1.0/cc;
		k = (a+b+c)*(b+c-a)*(a+c-b)*(a+b-c);
		if(k <= 1e-9)
		{
			printf("These are invalid inputs!\n");
			if(!--count)
			{
				break;
			}
			continue;
		}
		k = 2.0/sqrt(k);
		printf("%.3lf\n", k/2);
	}
	return 0;
}
