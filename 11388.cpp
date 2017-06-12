#include <stdio.h>
#include <math.h>

int gcd(long long p, long long q)
{
	if(p % q)
	{
		return gcd(q, p%q);
	}
	return q;
}

int main()
{
	int count, a, b, sq;
	long long i, product, p, q;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &a, &b);
		product = (long long)a * b;
		sq = (int)sqrt((double)product) + 1;
		for(i=a; i<sq; i+=a)
		{
			if(!(product % i))
			{
				p = i;
				q = product / i;
				if(gcd(p, q) == a)
				{
					printf("%lld %lld\n", p, q);
					break;
				}
			}
		}
		if(i >= sq)
		{
			printf("-1\n");
		}
	}
	return 0;
}
