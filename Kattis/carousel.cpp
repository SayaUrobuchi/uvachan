#include <iostream>

int main()
{
	int n, m, i;
	long long a, b, c, d;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i=0, d=2147483647, c=1; i<n; i++)
		{
			scanf("%lld%lld", &a, &b);
			if (a <= m)
			{
				if (b*c < d*a || (b*c == d*a && a > c))
				{
					c = a;
					d = b;
				}
			}
		}
		if (d == 2147483647 && c == 1)
		{
			puts("No suitable tickets offered");
		}
		else
		{
			printf("Buy %d tickets for $%d\n", c, d);
		}
	}
	return 0;
}
