#include <stdio.h>
#include <math.h>

int prime[140], tbl[805];

int main()
{
	int i, j, k, l, n, b, t, p, q, sum, res, count, m;
	double num;
	prime[0] = 2;
	for(i=3, j=1; i<30; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[j++] = i;
			for(k=i*i, l=i+i; k<800; k+=l)
			{
				tbl[k] = 1;
			}
		}
	}
	for(; i<800; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[j++] = i;
		}
	}
	m = j;
	while(scanf("%d%d", &n, &b) == 2)
	{
		for(i=0, t=b, res=2147483647; i<m&&prime[i]<=t; i++)
		{
			if(t % prime[i] == 0)
			{
				p = prime[i];
				count = 0;
				while(t%p==0)
				{
					t /= p;
					count++;
				}
				for(q=n, sum=0; q; sum+=(q/=p));
				sum /= count;
				if(sum < res)
				{
					res = sum;
				}
			}
		}
		for(num=0, i=2; i<=n; i++)
		{
			num += log(i);
		}
		printf("%d %d\n", res, (int)(num/log(b)+1e-10)+1);
	}
	return 0;
}

