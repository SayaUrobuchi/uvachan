#include <stdio.h>

int prime[2703670], ans[2703670];

int main()
{
	int cas, i, j, k, n;
	cas = 0;
	for(i=3; i<1660; i+=2)
	{
		if(prime[i] == 0)
		{
			for(j=i*i, k=i+i; j<2703664; j+=k)
			{
				prime[j] = i;
			}
		}
	}
	ans[2] = 1;
	prime[2] = 1;
	for(i=3; i<2703664; i++)
	{
		if(prime[i])
		{
			ans[i] = ans[i-1] + (prime[i] = prime[i/prime[i]] + 1);
		}
		else
		{
			ans[i] = ans[i-1] + (prime[i] = 1);
		}
		i++;
		ans[i] = ans[i-1] + (prime[i] = prime[i>>1] + 1);
	}
	while(scanf("%d", &n) == 1)
	{
		if(n < 0)
		{
			break;
		}
		if(n)
		{
			for(i=0, j=2703663; i<=j; )
			{
				k = ((i+j) >> 1);
				if(ans[k] == n)
				{
					printf("Case %d: %d!\n", ++cas, k);
					break;
				}
				else if(ans[k] > n)
				{
					j = k - 1;
				}
				else
				{
					i = k + 1;
				}
			}
			if(i > j)
			{
				printf("Case %d: Not possible.\n", ++cas);
			}
		}
		else
		{
			printf("Case %d: 0!\n", ++cas);
		}
	}
	return 0;
}
