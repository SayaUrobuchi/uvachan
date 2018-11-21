#include <stdio.h>

int prime[2500000], tbl[10000050];

int main()
{
	int i, j, k, pnum;
	long long t, n, ans;
	prime[0] = 2;
	for(i=3, pnum=1; i<3333; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pnum++] = i;
			for(j=i*i, k=i+i; j<10000050; j+=k)
			{
				tbl[j] = 1;
			}
		}
	}
	for(; i<10000050; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pnum++] = i;
		}
	}
	while(scanf("%lld", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		if(n < 0)
		{
			n = -n;
		}
		t = n;
		for(i=0, k=0; i<pnum; i++)
		{
			if((long long)prime[i] * prime[i] > n)
			{
				break;
			}
			if(n % prime[i] == 0)
			{
				do
				{
					n /= prime[i];
				}while(n % prime[i] == 0);
				ans = prime[i];
				k++;
			}
		}
		if(t == n)
		{
			printf("-1\n");
		}
		else
		{
			if(n > ans)
			{
				ans = n;
				k++;
			}
			if(k > 1)
			{
				printf("%lld\n", ans);
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}
