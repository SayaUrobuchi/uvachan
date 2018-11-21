#include <stdio.h>

int prime[5005], tbl[40005];
int pn;

int main()
{
	int i, j, k, n;
	prime[0] = 2;
	pn = 1;
	for(i=3; i<200; i+=2)
	{
		if(tbl[i] == 0)
		{
			for(j=i*i, k=i+i; j<40000; j+=k)
			{
				tbl[j] = 1;
			}
			prime[pn++] = i;
		}
	}
	for(; i<40000; i+=2)
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
		for(i=2, j=0; i<=n; i++)
		{
			j += prime[n-i];
			if(j >= i)
			{
				j %= i;
			}
		}
		printf("%d\n", j+1);
	}
	return 0;
}
