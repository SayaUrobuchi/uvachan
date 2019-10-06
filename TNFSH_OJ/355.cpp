#include <stdio.h>

int main()
{
	int n, i, p, q, r;
	while (scanf("%d%*d", &n) == 1)
	{
		scanf("%d%d", &p, &q);
		if (p > q)
		{
			p ^= q ^= p ^= q;
		}
		for (i=2; i<n; i++)
		{
			scanf("%d", &r);
			if (r > q)
			{
				p = q;
				q = r;
			}
			else if (r > p)
			{
				p = r;
			}
		}
		printf("%d\n", p);
	}
	return 0;
}
