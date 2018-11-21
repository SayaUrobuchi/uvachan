#include <stdio.h>

long long calc(int n)
{
	long long res;
	int i;
	if (n <= 0)
	{
		return 0;
	}
	res = 0;
	++n;
	for (i=1; i<=31; i++)
	{
		res += (n>>i) << (i-1);
		if ((n & ((1<<i)-1)) > (1<<(i-1)))
		{
			res += (n & ((1<<i))-1) - (1<<(i-1));
		}
	}
	return res;
}

int main()
{
	int cas, n, m;
	cas = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		printf("Case %d: %lld\n", ++cas, calc(m)-calc(n-1));
	}
	return 0;
}
