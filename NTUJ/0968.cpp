#include <stdio.h>
#include <math.h>

int tbl[100005], prime[100005], ary[1005];

int main()
{
	int cas, i, j, k, pn, an, n, m, o, sq, t;
	long long sav, res, ans;
	cas = 0;
	for(j=4; j<=100000; j+=2)
	{
		tbl[j] = 2;
	}
	prime[0] = 2;
	for(i=3, pn=1; i<=1000; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pn++] = i;
			for(j=i*i, k=i+i; j<=100000; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	for(; i<=100000; i+=2)
	{
		if(tbl[i] == 0)
		{
			prime[pn++] = i;
		}
	}
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(n == 0 && m == 0 && o == 0)
		{
			break;
		}
		for(i=0, an=0, sq=sqrt(n); i<pn&&prime[i]<=sq; i++)
		{
			if(n % prime[i] == 0)
			{
				ary[an] = 0;
				while(n % prime[i] == 0)
				{
					n /= prime[i];
					ary[an]++;
				}
				ary[an] *= m;
				an++;
			}
		}
		if(n > 1)
		{
			ary[an++] = m;
		}
		for(i=0, ans=0; i<an; i++)
		{
			for(j=0, sav=1; j<i; j++)
			{
				sav *= ary[j] / (o+1) + 1;
				sav %= 100000007;
			}
			sav *= ary[j] / o - ary[j] / (o+1);
			sav %= 100000007;
			for(j=i+1; j<an; j++)
			{
				sav *= ary[j] / o + 1;
				sav %= 100000007;
			}
			ans += sav;
			ans %= 100000007;
		}
		printf("Case %d: %d\n", ++cas, (int)ans);
	}
	return 0;
}
