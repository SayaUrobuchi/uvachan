#include <stdio.h>
#include <math.h>

int prime[1860000];

int main()
{
	long long n;
	int i, j, nsqrt, ans, tmp, *ptr, *ptr2;
	prime[0] = 3;
	prime[1] = 5;
	for(i=7, ptr2=prime + 2; i<30000101; i+=2)
	{
		tmp = sqrt(i) + 1;
		for(j=0, ptr=prime; *ptr<tmp; j++, ptr++)
		{
			if(!(i % *ptr))
			{
				break;
			}
		}
		if(*ptr >= tmp)
		{
			*(ptr2++) = i;
		}
	}
	while(scanf("%lld", &n) == 1)
	{
		if(n < 3)
		{
			printf("1\n");
		}
		else
		{
			if(!(n % 2))
			{
				while(!(n % 2))
				{
					n /= 2;
				}
			}
			nsqrt = sqrt(n) + 1;
			for(ans=1, ptr=prime; *ptr<nsqrt && n > 1; ptr++)
			{
				if(!(n % *ptr))
				{
					tmp = 1;
					while(!(n % *ptr))
					{
						tmp++;
						n /= *ptr;
					}
					ans *= tmp;
				}
			}
			if(n > 1)
			{
				ans *= 2;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}