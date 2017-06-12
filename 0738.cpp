#include <stdio.h>
#include <string.h>

int prime[1000005], tbl[1000050], par[1000005];

int get_par(int p)
{
	if(par[p] == -1)
	{
		return p;
	}
	return par[p]=get_par(par[p]);
}

int main()
{
	int cas, count, c, i, j, k, l, p, q, cc, temp;
	long long a, b, d, e;
	cas = 0;
	prime[0] = 2;
	for(i=3, j=1; i<=1025; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[j++] = i;
			for(k=i*i, l=i+i; k<=1000035; k+=l)
			{
				tbl[k] = 1;
			}
		}
	}
	for(; i<=1000035; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[j++] = i;
		}
	}
	scanf("%d", &count);
	while(scanf("%lld%lld%d", &a, &b, &c) == 3)
	{
		memset(par, -1, sizeof(par));
		for(p=0, q=j-1; p<=q; )
		{
			cc = ((p+q)>>1);
			if(prime[cc] < c)
			{
				p = cc + 1;
			}
			else
			{
				q = cc - 1;
				temp = cc;
			}
		}
		cc = b-a+1;
		for(i=temp, cc=b-a+1; prime[i]<=b-a+1; i++)
		{
			for(d=e=(1+(a-1)/prime[i])*prime[i]; e<=b; e+=prime[i])
			{
				if((p=get_par(d-a)) != (q=get_par(e-a)))
				{
					par[q] = p;
					cc--;
				}
			}
		}
		printf("Case #%d: %d\n", ++cas, cc);
	}
	return 0;
}
