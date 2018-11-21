#include <stdio.h>
#include <math.h>

unsigned int getmod(unsigned int now, int degree, int mod)
{
	unsigned int tmp;
	if(degree)
	{
		if(degree % 2)
		{
			return (now * getmod(now, degree - 1, mod)) % mod;
		}
		else
		{
			tmp = getmod(now, degree/2, mod);
			return (tmp * tmp) % mod;
		}
	}
	return 1;
}

int main()
{
	int n, i, j, tmp;
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		i = 0;
		if(n % 2)
		{
			tmp = sqrt(n) + 1;
			for(i=3; i<tmp; i+=2)
			{
				if(!(n % i)) break;
			}
		}
		if(i < tmp)
		{
			for(i=2; i<n; i++)
			{
				if(i != getmod(i, n, n)) break;
			}
			if(i == n && n != 2) printf("The number %d is a Carmichael number.\n", n);
			else printf("%d is normal.\n", n);
		}
		else
		{
			printf("%d is normal.\n", n);
		}
	}
	return 0;
}
