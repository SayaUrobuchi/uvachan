#include <stdio.h>

double px[100005], py[100005];

int main()
{
	int n, i;
	double res;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, res=0; i<n; i++)
		{
			scanf("%lf%lf", &px[i], &py[i]);
			if(i)
			{
				res += px[i-1] * py[i] - px[i] * py[i-1];
			}
		}
		res += px[i-1] * py[0] - px[0] * py[i-1];
		res /= 2;
		if(res < 0)
		{
			res = -res;
		}
		printf("%.3lf\n", res);
	}
	return 0;
}
