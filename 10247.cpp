#include <stdio.h>
#include <string.h>
#include <math.h>

short degree[3300];
unsigned long bignum[1550];

int POW(int n, int m)
{
	int tmp;
	if(!m)
	{
		return 1;
	}
	if(m % 2)
	{
		return n * POW(n, m-1);
	}
	tmp = POW(n, m/2);
	return tmp * tmp;
}

void kill(int n, int m)
{
	short *ptr;
	for(ptr=degree+n; ; ptr+=n)
	{
		if(!(*ptr % n))
		{
			while(m && !(*ptr % n))
			{
				*ptr /= n;
				m--;
			}
			if(!m) return;
		}
	}
}

int main()
{
	int k, d, i, j, n, m, divide, times, tmp, dsqrt, len;
	short *ptr;
	unsigned long *ptr2;
	m = 0;
	while(scanf("%d%d", &k, &d) == 2)
	{
		if(k == 1)
		{
			printf("1\n");
			continue;
		}
		n = (POW(k, d+1) - 1) / (k - 1);
		n++;
		for(i=2; i<n; i++)
		{
			degree[i] = i;
		}
		for(j=0, divide=k+1, times=POW(k, d-1); j<d; j++, divide*=k, divide++, times/=k)
		{
			tmp = divide;
			m = 0;
			if(!(tmp % 2))
			{
				while(!(tmp % 2))
				{
					tmp /= 2;
					m++;
				}
				kill(2, m * times);
			}
			dsqrt = sqrt(divide) + 1;
			for(i=3; i<dsqrt; i+=2)
			{
				if(!(tmp % i))
				{
					m = 0;
					while(!(tmp % i))
					{
						tmp /= i;
						m++;
					}
					kill(i, m * times);
				}
			}
			if(tmp > 1)
			{
				kill(tmp, times);
			}
		}
		len = 1;
		bignum[0] = 1;
		for(i=2, ptr=degree+2; i<n; i++, ptr++)
		{
			if(*ptr > 1)
			{
				ptr2 = bignum;
				for(j=0; j<len; j++, ptr2++)
				{
					*ptr2 *= *ptr;
				}
				for(j=1, ptr2=bignum+1; j<len; j++, ptr2++)
				{
					if(*(ptr2-1) > 999999)
					{
						*ptr2 += *(ptr2-1) / 1000000;
						*(ptr2-1) %= 1000000;
					}
				}
				if(*(ptr2-1) > 999999)
				{
					while(*(ptr2-1) > 9999)
					{
						*ptr2 = *(ptr2-1) / 1000000;
						*(ptr2-1) %= 1000000;
						len++;
						ptr2++;
					}
				}
			}
		}
		printf("%d", bignum[len-1]);
		for(i=len-2; i>-1; i--)
		{
			printf("%06d", bignum[i]);
		}
		printf("\n");
	}
	return 0;
}