#include <stdio.h>
#include <math.h>

const int N = 30000020;
const int PN = 1900000;

int prime[PN];
int tbl[N];

int main()
{
	int m, i, j, k, c, *p;
	long long n, t, ans;
	for(i=3, m=0; i<5480; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[m++] = i;
			for(j=i*i, k=i+i; j<N; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	for(; i<N; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[m++] = i;
		}
	}
	while(scanf("%lld", &n) == 1)
	{
		if (!n)
		{
			puts("1");
			continue;
		}
		for(t=n; !(t&1); t>>=1);
		for(p=prime, ans=1; t>=N&&(long long)*p**p<=t&&t>1; p++)
		{
			if(t % *p == 0)
			{
				for(t/=*p, c=2; t%(*p)==0; t/=(*p), c++);
				ans *= c;
			}
		}
		if (t < N && t > 1)
		{
			while (t > 1)
			{
				i = tbl[t];
				if (!i)
				{
					i = t;
				}
				for(t/=i, c=2; t%i==0; t/=i, c++);
				ans *= c;
			}
		}
		if(t > 1)
		{
			ans <<= 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
