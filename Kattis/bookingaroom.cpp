#include <stdio.h>

int ucnt, tbl[1024];

int main()
{
	int n, m, i, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		++ucnt;
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			tbl[t] = ucnt;
		}
		if (n == m)
		{
			puts("too late");
			continue;
		}
		for (i=1; i<=n; i++)
		{
			if (tbl[i] != ucnt)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
