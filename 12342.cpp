#include <stdio.h>
#include <math.h>

int main()
{
	int cas, count, n, m;
	double res;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		res = 0;
		n -= 180000;
		if (n < 0)
		{
			n = 0;
		}
		m = (n > 300000 ? 300000 : n);
		res += m * .1;
		n -= 300000;
		if (n < 0)
		{
			n = 0;
		}
		m = (n > 400000 ? 400000 : n);
		res += m * .15;
		n -= 400000;
		if (n < 0)
		{
			n = 0;
		}
		m = (n > 300000 ? 300000 : n);
		res += m * .2;
		n -= 300000;
		if (n < 0)
		{
			n = 0;
		}
		m = n;
		res += m * .25;
		if (res > 0 && res < 2000)
		{
			res = 2000;
		}
		printf("Case %d: %.0f\n", ++cas, ceil(res));
	}
	return 0;
}
