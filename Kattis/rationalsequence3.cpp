#include <stdio.h>

long long p, q;

void recurs(int cur)
{
	if (cur > 1)
	{
		recurs(cur>>1);
		if (cur & 1)
		{
			p += q;
		}
		else
		{
			q += p;
		}
	}
}

int main()
{
	int count, cas, n;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &cas, &n);
		p = q = 1;
		recurs(n);
		printf("%d %lld/%lld\n", cas, p, q);
	}
	return 0;
}
