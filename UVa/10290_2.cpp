#include <stdio.h>
#include <math.h>
#include <string.h>

char table[30000101], *ptr2, *ptr3;
int prime[1860000];

int main()
{
	long long n;
	int i, j, nsqrt, ans, tmp, *ptr;
	memset(table, 1, sizeof(table));
	ptr = prime;
	ptr2 = table + 3;
	for(i=3; i<30000101; i+=2, ptr2+=2)
	{
		if(*ptr2)
		{
			*(ptr++) = i;
			tmp = i + i;
			j = i + tmp;
			ptr3 = &table[j];
			while(j < 30000101)
			{
				*ptr3 = 0;
				ptr3 += tmp;
				j += tmp;
			}
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
			if(n % 2)
			{
				if(n < 30000101 && table[n])
				{
					printf("2\n");
					continue;
				}
			}
			else
			{
				while(!(n % 2))
				{
					n /= 2;
				}
			}
			nsqrt = sqrt(n) + 1;
			for(ans=1, ptr=prime; *ptr<nsqrt; ptr++)
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
					if(n == 1) break;
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