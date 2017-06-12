#include <stdio.h>

int ary[32];

int main()
{
	int n, m, i, p, q, r;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			ary[p] -= r;
			ary[q] += r;
		}
		for (i=1; i<=n; i++)
		{
			if (ary[i] < 0)
			{
				break;
			}
		}
		puts(i<=n ? "N" : "S");
	}
	return 0;
}
