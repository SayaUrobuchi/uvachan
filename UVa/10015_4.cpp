#include <stdio.h>

int prime[5005], tbl[40005];
int pn;

int joseph(int n, int d)
{
	if(n == 1)
	{
		return 0;
	}
	return (joseph(n-1, d+1)+prime[d])%n;
}

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
		printf("%d\n", joseph(n, 0)+1);
	}
	return 0;
}
