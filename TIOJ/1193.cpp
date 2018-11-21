#include <stdio.h>

int main()
{
	int n, m, i;
	long long res, cmp;
	cmp = (1ll << 42);
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=2, res=1; i<=n; i++)
		{
			res *= i;
			if(res > cmp)
			{
				res %= m;
			}
		}
		if(res >= m)
		{
			res %= m;
		}
		printf("%I64d\n", res);
	}
	return 0;
}
