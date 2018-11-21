#include <stdio.h>
#include <string.h>

long long recurs(long long p, long long q, long long r, long long t)
{
	int i, j;
	long long res;
	if(p == 0)
	{
		return 0;
	}
	res = 0;
	if(p >= 10)
	{
		for(i=1; i<10; i++)
		{
			res += (p/10-1)*i*i*t;
			res += (i-1)*i*t;
		}
	}
	//printf("!! %lld %lld %lld %lld: %lld\n", p, q, r, t, res);
	//123 4 56
	//  ^
	for(i=(p>=10?0:1); i<p%10; i++)
	{
		for(j=i+1; j<10; j++)
		{
			res += j*t;
		}
	}
	//printf("!! %lld %lld %lld %lld: %lld\n", p, q, r, t, res);
	//123 4 56
	//    ^
	for(i=p%10+1; i<q; i++)
	{
		res += i*t;
	}
	//printf("!! %lld %lld %lld %lld: %lld\n", p, q, r, t, res);
	//123 4 56
	//      ^
	if(p%10 < q)
	{
		for(i=0; i<r/t&&i<q; i++)
		{
			res += t;
		}
		//printf("!! %lld %lld %lld %lld: %lld\n", p, q, r, t, res);
		if(r/t < q)
		{
			res += r%t+1;
		}
		//printf("!! %lld %lld %lld %lld: %lld\n", p, q, r, t, res);
	}
	return res+recurs(p/10, p%10, r+q*t*10, t*10);
}

long long calc(long long t)
{
	if(t < 100)
	{
		return 0;
	}
	//printf("!! %lld\n", recurs(t/100, (t%100)/10, t%10, 1));
	return recurs(t/100, (t%100)/10, t%10, 1);
}

int main()
{
	int count, i, j, k, l, o, r, len;
	long long ans, lp, lq;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lld%lld", &lp, &lq);
		printf("%lld\n", calc(lq)-calc(lp-1));
	}
	return 0;
}
