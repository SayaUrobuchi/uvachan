#include <stdio.h>
#include <math.h>

int main()
{
	int ans, temp, type, d;
	double n, m, s, t1, t2;
	s = sqrt(3.0) / 2.0;
	while(scanf("%lf%lf", &n, &m) == 2)
	{
		ans = (int)n * (int)m;
		type = 1;
		d = n - 0.5;
		temp = t1 = (m - 1) / s + 1;
		temp *= (int)d;
		if(temp > ans)
		{
			ans = temp;
			type = 0;
		}
		temp = t1;
		temp *= (int)n;
		temp -= ((int)t1) / 2;
		if(temp > ans)
		{
			ans = temp;
			type = 0;
		}
		d = m - 0.5;
		temp = t2 = (n - 1) / s + 1;
		temp *= (int)d;
		if(temp > ans)
		{
			ans = temp;
			type = 0;
		}
		temp = t2;
		temp *= (int)m;
		temp -= ((int)t2) / 2;
		if(temp > ans)
		{
			ans = temp;
			type = 0;
		}
		if(type)
		{
			printf("%d grid\n", ans);
		}
		else
		{
			printf("%d skew\n", ans);
		}
	}
	return 0;
}
