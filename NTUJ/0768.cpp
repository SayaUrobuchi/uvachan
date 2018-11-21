#include <stdio.h>

int f(int bas, int tim)
{
	int t;
	if(tim == 0)
	{
		return 1;
	}
	if(tim & 1)
	{
		return (int)(((long long)bas * f(bas, tim-1)) % 1000000007);
	}
	t = f(bas, tim>>1);
	return (int)(((long long)t * t) % 1000000007);
}

int main()
{
	int count, cas, n;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("Case #%d: %d\n", ++cas, (int)((f(2, n-1)*(long long)n)%1000000007));
	}
	return 0;
}
