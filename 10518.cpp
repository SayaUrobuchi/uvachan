#include <stdio.h>

int ary[1000000];

int main()
{
	int cas, b, i;
	long long n;
	cas = 0;
	while(scanf("%lld%d", &n, &b) == 2)
	{
		if(!n && !b)
		{
			break;
		}
		if(n < 2)
		{
			printf("Case %d: %lld %d 1\n", ++cas, n, b);
			continue;
		}
		ary[0] = 1;
		ary[1] = 1;
		for(i=2; ; i++)
		{
			ary[i] = ary[i-1] + ary[i-2] + 1;
			ary[i] %= b;
			if(ary[i] == 1 && ary[i-1] == 1)
			{
				i--;
				break;
			}
		}
		printf("Case %d: %lld %d %d\n", ++cas, n, b, ary[n%i]);
	}
	return 0;
}
