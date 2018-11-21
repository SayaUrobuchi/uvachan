#include <stdio.h>

long long j;
long long ary[100005];

int main()
{
	int n, i;
	ary[1] = 0;
	for(i=2, j=1; i<=100000; i++)
	{
		ary[i] = ary[i-1] + j;
		j += (long long)i*i;
	}
	while(scanf("%d", &n) == 1)
	{
		printf("%lld\n", ary[n]);
	}
	return 0;
}
