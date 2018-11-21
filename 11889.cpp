#include <stdio.h>

int main()
{
	int count, n, m, res, i, t, u;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		if (m % n)
		{
			puts("NO SOLUTION");
		}
		else
		{
			res = 1;
			if (!(m & 1))
			{
				t = 1;
				u = 0;
				while (!(m&1))
				{
					m >>= 1;
					if (!(n&1))
					{
						n >>= 1;
					}
					else
					{
						u = 1;
					}
					t <<= 1;
				}
				if (u)
				{
					res = t;
				}
			}
			for (i=3; i*i<=m; i+=2)
			{
				if (!(m % i))
				{
					t = 1;
					u = 0;
					while (!(m%i))
					{
						m /= i;
						if (!(n % i))
						{
							n /= i;
						}
						else
						{
							u = 1;
						}
						t *= i;
					}
					if (u)
					{
						res *= t;
					}
				}
			}
			if (m > 1)
			{
				if (n % m)
				{
					res *= m;
				}
				else
				{
					n /= i;
				}
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
