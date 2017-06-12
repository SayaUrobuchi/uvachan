#include <stdio.h>
#include <math.h>

int main()
{
	int cas, count;
	double d, v, u, t;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lf%lf%lf", &d, &v, &u);
		if(u <= v || v == 0.0)
		{
			printf("Case %d: can't determine\n", ++cas);
			continue;
		}
		t = sqrt(u*u - v*v);
		printf("Case %d: %.3lf\n", ++cas, d/t-d/u);
	}
	return 0;
}

