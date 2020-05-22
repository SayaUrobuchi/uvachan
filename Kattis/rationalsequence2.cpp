#include <stdio.h>

int stk[1048576];

int main()
{
	int count, cas, sn;
	long long i, p, q;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%lld/%lld", &cas, &p, &q);
		for (sn=-1; p!=1||q!=1; )
		{
			if (p < q)
			{
				stk[++sn] = 0;
				q -= p;
			}
			else
			{
				stk[++sn] = 1;
				p -= q;
			}
		}
		for (i=1; sn>=0; sn--)
		{
			i = (i<<1) + stk[sn];
		}
		printf("%d %lld\n", cas, i);
	}
	return 0;
}
