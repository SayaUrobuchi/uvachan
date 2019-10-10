#include <stdio.h>
#include <math.h>

long long prime[1900000];
char tbl[4000000];

int main()
{
	int m, i, j, k, c, sq;
	long long n, t, ans, *p;
	for(i=3, m=0; i<5480; i+=2)
	{
		if((tbl[i>>3] & (1<<(i%8))) == 0)
		{
			prime[m++] = i;
			for(j=i*i, k=i+i; j<=30000020; j+=k)
			{
				tbl[j>>3] |= (1<<(i%8));
			}
		}
	}
	for(; i<=30000020; i+=2)
	{
		if((tbl[i>>3] & (1<<(i%8))) == 0)
		{
			prime[m++] = i;
		}
	}
	while(scanf("%lld", &n) == 1)
	{
		for(t=n; !(t&1); t>>=1);
		/*for(p=prime, ans=1; (*p)*(*p)<=n&&t>1; p++)*/
		for(p=prime, ans=1, sq=sqrt(n)+1; *p<sq&&t>1; p++)
		{
			if(t % *p == 0)
			{
				for(t/=*p, c=2; t%(*p)==0; t/=(*p), c++);
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
