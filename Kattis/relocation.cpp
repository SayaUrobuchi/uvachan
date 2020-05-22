#include <stdio.h>
#include <stdlib.h>

int ary[1048576];

int main()
{
	int n, m, i, p, q, r;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &r, &p, &q);
			if (r == 1)
			{
				ary[p] = q;
			}
			else
			{
				printf("%d\n", abs(ary[p]-ary[q]));
			}
		}
	}
	return 0;
}
