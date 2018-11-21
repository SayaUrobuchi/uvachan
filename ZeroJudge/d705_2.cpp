#include <stdio.h>
#include <math.h>

int tbl[1000005], prime[500000];

int main()
{
	int n, i, j, k, pn, sq;
	tbl[1] = 1;
	prime[0] = 2;
	for(i=4; i<=1000000; i+=2)
	{
		tbl[i] = 1;
	}
	for(i=3, pn=1; i<=1000; i+=2)
	{
		if(tbl[i] == 0)
		{
			for(j=i*i, k=i+i; j<=1000000; j+=k)
			{
				tbl[j] = 1;
			}
			prime[pn++] = i;
		}
	}
	for(; i<=1000000; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pn++] = i;
		}
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		if(n <= 1000000)
		{
			printf("%d\n", tbl[n]);
		}
		else if((n&1) == 0)
		{
			printf("1\n");
		}
		else
		{
			sq = (int)(floor(sqrt(n))+1e-8);
			for(i=1; i<pn; i++)
			{
				if(prime[i] > sq)
				{
					i = pn;
					break;
				}
				if(n % prime[i] == 0)
				{
					break;
				}
			}
			if(i < pn)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
