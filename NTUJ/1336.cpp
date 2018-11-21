#include <stdio.h>

int prime[1000000], tbl[1000000];

int main()
{
	int i, j, k, c, p, q, pn, n, ans, count;
	prime[0] = 2;
	for(i=3, pn=1; i<=300; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pn++] = i;
			for(j=i*i, k=i+i; j<=50000; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	for(; i<=50000; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pn++] = i;
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		if(n == 8)
		{
			printf("8\n");
			continue;
		}
		ans = 0;
		for(i=0; prime[i]<=n/prime[i]; i++)
		{
			p = 0;
			q = pn-1;
			while(p<=q)
			{
				c = ((p+q)>>1);
				if((long long)prime[c]*prime[i] > n)
				{
					q = c-1;
				}
				else
				{
					k = c;
					p = c+1;
				}
			}
			if(k >= i)
			{
				ans = prime[k]*prime[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
