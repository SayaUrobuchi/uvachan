#include <iostream>
using namespace std;

long long dis(long long x, long long y)
{
	return x*x+y*y;
}

int main()
{
	int n, i, j, ax, ay;
	long long best;
	//fprintf(stderr, "%lld %lld\n", 1*1+90210LL*90210LL, 69551LL*69551+57450LL*57450);
	scanf("%d", &n);
	for (i=1, j=n, ax=0, ay=n+1, best=dis(0, n+1); i<=n; i++)
	{
		for (; dis(i, j)>(long long)n*n; j--);
		long long d = dis(i, j+1);
		if (d < best)
		{
			best = d;
			ax = i;
			ay = j+1;
		}
	}
	printf("%d %d\n", ax, ay);
	return 0;
}
