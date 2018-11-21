#include <stdio.h>
#include <math.h>

int pnum, id, acnt, brp;
int prime[3000000], ans[200005], tt[15];
unsigned int tbl[13000005];

int main()
{
	int count, i, j, k, n;
	prime[0] = 2;
	for(i=3, pnum=1, acnt=1; i<=4000; i+=2)
	{
		if(tbl[i] == 0)
		{
			for(j=i*i, k=i+i; j<=13000000; j+=k)
			{
				tbl[j] = 1;
			}
			prime[pnum++] = i;
		}
	}
	for(; i<=13000000; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pnum++] = i;
		}
	}
	for(i=4; i<pnum&&acnt<=100000; i++)
	{
		for(j=0, k=prime[i]; k>0; )
		{
			j *= 10;
			j += k%10;
			k /= 10;
		}
		if(prime[i] != j && j%2)
		{
			if(j < 13000000)
			{
				if(tbl[j] == 0)
				{
					ans[acnt++] = prime[i];
				}
				continue;
			}
			for(k=1; k<pnum&&prime[k]*prime[k]<=j; k++)
			{
				if(j % prime[k] == 0)
				{
					break;
				}
			}
			if(!(k<pnum&&prime[k]*prime[k]<=j))
			{
				ans[acnt++] = prime[i];
			}
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
