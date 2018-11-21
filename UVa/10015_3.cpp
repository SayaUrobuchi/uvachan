#include <stdio.h>

int prime[4000], tbl[33000], next[4000];

int main()
{
	int n, i, j, k, l, s, c;
	prime[0] = 2;
	for(i=3, l=1; i<200; i+=2)
	{
		if(!tbl[i])
		{
			prime[l++] = i;
			for(j=i*i, s=i+i; j<33000; j+=s)
			{
				tbl[j] = 1;
			}
		}
	}
	for(; i<33000; i+=2)
	{
		if(!tbl[i])
		{
			prime[l++] = i;
		}
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			tbl[i] = 1;
			next[i] = i+1;
		}
		next[i-1] = 0;
		for(j=0, k=0, s=i-1; n>1; n--, k++)
		{
			for(c=0, l=(prime[k]-1)%n; c<l; c++)
			{
				s = j;
				j = next[j];
			}
			next[s] = next[j];
			j = next[j];
		}
		printf("%d\n", j+1);
	}
	return 0;
}
