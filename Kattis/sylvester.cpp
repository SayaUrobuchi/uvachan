#include <iostream>

int recurs(long long n, long long r, long long c)
{
	int mod;
	if (n == 1)
	{
		return 1;
	}
	n >>= 1;
	mod = 1;
	if (r >= n && c >= n)
	{
		mod = -1;
	}
	if (r >= n)
	{
		r -= n;
	}
	if (c >= n)
	{
		c -= n;
	}
	return recurs(n, r, c) * mod;
}

int main()
{
	int count;
	long long n, i, j, x, y, w, h;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%lld%lld%lld%lld%lld", &n, &x, &y, &w, &h);
		for (i=y; i<y+h; i++)
		{
			printf("%d", recurs(n, i, x));
			for (j=x+1; j<x+w; j++)
			{
				printf(" %d", recurs(n, i, j));
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
