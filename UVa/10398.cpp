#include <stdio.h>
#include <math.h>

#define STEP 1e-20

int main()
{
	int times;
	double left, right, center, ans, p4, p5, s, final;
	for(left=1.0, right=2.0; left<=right; )
	{
		center = left + right;
		center /= 2.0;
		p4 = center * center * center * center;
		p5 = p4 * center;
		if(fabs(1.0+p4-p5) < 1e-16)
		{
			ans = center;
			break;
		}
		if(1.0 + p4 < p5)
		{
			right = center - STEP;
		}
		else
		{
			left = center + STEP;
		}
	}
	/*printf("%.4lf %.4lf %.4lf\n", ans, ans*ans*ans*ans, ans*ans*ans*ans*ans);*/
	while(scanf("%lf%d", &s, &times) == 2)
	{
		if(s == 0.0)
		{
			printf("0\n");
			continue;
		}
		final = log10(s) + log10(ans) * (times-1);
		if(final < 9.0)
		{
			printf("%d\n", (int)(s * pow(ans, times-1)));
		}
		else
		{
			printf("%d\n", (int)final+1);
		}
	}
	return 0;
}
