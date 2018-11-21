#include <stdio.h>

int ary[15];

long long gcd(long long p, long long q)
{
	while((p%=q)&&(q%=p));
	return p+q;
}

int main()
{
	int count, n, i, cas;
	long long m, son, mon, g;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, m=1; i<n; i++)
		{
			scanf("%d", &ary[i]);
			m *= ary[i];
		}
		son = n * m;
		mon = 0;
		for(i=0; i<n; i++)
		{
			mon += m/ary[i];
		}
		g = gcd(son, mon);
		son /= g;
		mon /= g;
		printf("Case %d: %lld/%lld\n", ++cas, son, mon);
	}
	return 0;
}
