#include <stdio.h>

int main()
{
	int count, n, i, p, q, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, p=2147483647, q=-2147483647; i<n; i++)
		{
			scanf("%d", &t);
			if (t < p)
			{
				p = t;
			}
			if (t > q)
			{
				q = t;
			}
		}
		printf("%d\n", (q-p)<<1);
	}
	return 0;
}
