#include <stdio.h>

int prime[4000], tbl[33000];

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
		}
		for(i=1, j=0, k=0; i<n; i++, k++)
		{
			for(c=0; c<prime[k]; )
			{
				c += tbl[j];
				if(c == prime[k])
				{
					break;
				}
				j++;
				if(j == n)
				{
					j = 0;
				}
			}
			tbl[j] = 0;
		}
		for(i=0; i<n; i++)
		{
			if(tbl[i])
			{
				break;
			}
		}
		printf("%d\n", i+1);
	}
	return 0;
}
