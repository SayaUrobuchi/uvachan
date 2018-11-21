#include <stdio.h>

int prime[10000], tbl[10021];

int main()
{
	int count, n, i, j, k, l;
	prime[0] = 2;
	for(i=3, l=1; i<110; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[l++] = i;
			for(j=i*i, k=i+i; j<10020; j+=k)
			{
				tbl[j] = 1;
			}
		}
	}
	for(; i<10020; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[l++] = i;
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		if(n <= 1)
		{
			printf("(%d)\n", n);
			continue;
		}
		for(i=0; i<l&&prime[i]<=n; i++)
		{
			for(j=0, k=n; k; j+=(k/=prime[i]));
			if(i)
			{
				printf("*");
			}
			if(j > 1)
			{
				printf("(%d^%d)", prime[i], j);
			}
			else
			{
				printf("(%d)", prime[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
