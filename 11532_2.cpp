#include <stdio.h>

int main()
{
	int count, n, m;
	long long res;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		res = 0;
		if (m > (n>>1) && (n&1))
		{
			--n;
			--m;
			res = 1;
		}
		while (n && m)
		{
			if (n > 1)
			{
				n -= 2;
				--m;
				res = (res<<3) | 5;
			}
			else
			{
				--n;
				--m;
				res = (res<<2) | 1;
			}
		}
		while (n)
		{
			--n;
			res = (res<<1) | 1;
		}
		printf("%lld\n", res);
	}
	return 0;
}
