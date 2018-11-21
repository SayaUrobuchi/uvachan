#include <stdio.h>

int main()
{
	int m, n, i, j, mon, res;
	double a, b, c, d, dec;
	while (scanf("%d%lf%lf%d", &m, &a, &b, &n) == 4)
	{
		if (m < 0)
		{
			break;
		}
		c = b+a;
		a = b/m;
		scanf("%d%lf", &mon, &dec);
		c *= (1-dec);
		d = dec;
		if (b < c)
		{
			res = 0;
		}
		for (i=1, j=1; i<n&&b>=c; i++)
		{
			scanf("%d%lf", &mon, &dec);
			for (; j<mon; j++)
			{
				b -= a;
				c *= (1-d);
				/*printf("%.3lf %.3lf\n", b, c);*/
				if (b < c)
				{
					res = j;
					break;
				}
			}
			d = dec;
		}
		for (; i<n; i++)
		{
			scanf("%d%lf", &mon, &dec);
		}
		for (; j<=m&&b>=c; j++)
		{
			b -= a;
			c *= (1-d);
			/*printf("%.3lf %.3lf\n", b, c);*/
			if (b < c)
			{
				res = j;
				break;
			}
		}
		printf("%d %s\n", res, res!=1?"months":"month");
	}
	return 0;
}
