#include <stdio.h>

int prime[10000];
char tbl[35001];

char isprime(int n)
{
	int i;
	for(i=1; prime[i]*prime[i]<=n; i++)
	{
		if(!(n % prime[i]))
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n, i, j, k;
	prime[0] = 2;
	for(i=3, k=1; i<200; i+=2)
	{
		if(!tbl[i])
		{
			prime[k++] = i;
			for(j=i*i; j<35001; j+=i)
			{
				tbl[j] = 1;
			}
		}
	}
	for(i; i<35001; i+=2)
	{
		if(!tbl[i])
		{
			prime[k++] = i;
		}
	}
	while(scanf("%d", &n) == 1)
	{
		if(n < 4)
		{
			printf("%d is not the sum of two primes!\n", n);
		}
		else if(n == 4)
		{
			printf("%d is the sum of 2 and 2.\n", n);
		}
		else if(n % 2)
		{
			if(isprime(n-2))
			{
				printf("%d is the sum of 2 and %d.\n", n, n-2);
			}
			else
			{
				printf("%d is not the sum of two primes!\n", n);
			}
		}
		else
		{
			for(i=n/2-1+n%2, j=n/2+1-n%2; ; i-=2, j+=2)
			{
				if(isprime(i) && isprime(j))
				{
					printf("%d is the sum of %d and %d.\n", n, i, j);
					break;
				}
			}
		}
	}
	return 0;
}
