#include <iostream>

int main()
{
	int n, m, a, b, wa, wb, p, q;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (a=0, b=0, wa=1, wb=1; n||m; n/=10, m/=10)
		{
			p = n%10;
			q = m%10;
			if (p >= q)
			{
				a += p * wa;
				wa *= 10;
			}
			if (q >= p)
			{
				b += q * wb;
				wb *= 10;
			}
		}
		if (wa != 1)
		{
			printf("%d\n", a);
		}
		else
		{
			puts("YODA");
		}
		if (wb != 1)
		{
			printf("%d\n", b);
		}
		else
		{
			puts("YODA");
		}
	}
	return 0;
}
