#include <stdio.h>
#include <math.h>

int main()
{
	long long n, m, o, t, c, i, res;
	double dd;
	while(scanf("%lld%lld%lld", &n, &m, &o) == 3)
	{
		for(i=2, res=n*m+o; (1ll<<i)<=n; i++)
		{
			t = ceil(pow(n, 1.0/i));
			c = t*i;
			dd = pow(t, i)*(t-1)/t;
			while(dd>=n)
			{
				dd = dd*(t-1)/t;
				c--;
			}
			if(res > c*m+i*o)
			{
				res = c*m+i*o;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
