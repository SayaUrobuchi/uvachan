#include <stdio.h>

int prime[5761500], dp[8];
char tbl[12500000];

char isprime(int n)
{
	int t1, t2;
	t1 = n / 8;
	t2 = n % 8;
	return (tbl[t1] | dp[t2]) != tbl[t1];
}

int main()
{
	int n, i, j, k, s, t1, t2;
	dp[0] = 1;
	for(i=1; i<8; i++)
	{
		dp[i] = dp[i-1] * 2;
	}
	prime[0] = 2;
	for(i=3, k=1; i<10100; i+=2)
	{
		t1 = i / 8;
		t2 = i % 8;
		if((tbl[t1] | dp[t2]) != tbl[t1])
		{
			s = i + i;
			prime[k++] = i;
			for(j=i*i; j<100000000; j+=s)
			{
				t1 = j / 8;
				t2 = j % 8;
				tbl[t1] |= dp[t2];
			}
		}
	}
	for(; i<100000000; i+=2)
	{
		t1 = i / 8;
		t2 = i % 8;
		if((tbl[t1] | dp[t2]) != tbl[t1])
		{
			prime[k++] = i;
		}
	}
	while(scanf("%d", &n) == 1)
	{
		if(n < 5 || n == 6)
		{
			printf("%d is not the sum of two primes!\n", n);
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
			i = j = n / 2;
			i = i - 1 + i % 2;
			j = j + 1 - j % 2;
			if(i == j)
			{
				i-=2;
				j+=2;
			}
			for(; ; i-=2, j+=2)
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
