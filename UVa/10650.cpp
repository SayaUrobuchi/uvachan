#include <stdio.h>

int tbl[32005], prime[5200], pa[5200], pb[5200];

int main()
{
	int i, j, k, pp, c, n, m, dif;
	prime[0] = 2;
	for(i=3, pp=1; i<200; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pp++] = i;
			for(j=i*i, k=i+i; j<32005; j+=k)
			{
				tbl[j] = 1;
			}
		}
	}
	for(; i<32005; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pp++] = i;
		}
	}
	for(i=0, c=0; i<pp; i++)
	{
		for(j=i+2, dif=prime[i+1]-prime[i]; j<pp; j++)
		{
			if(prime[j]-prime[j-1] != dif)
			{
				break;
			}
		}
		if(j-i > 2)
		{
			pa[c] = i;
			pb[c] = j-1;
			c++;
			i = j-2;
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		if(n > m)
		{
			i = n;
			n = m;
			m = i;
		}
		for(i=0; i<c; i++)
		{
			if(prime[pa[i]] >= n && prime[pb[i]] <= m)
			{
				printf("%d", prime[pa[i]]);
				for(j=pa[i]+1; j<=pb[i]; j++)
				{
					printf(" %d", prime[j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
