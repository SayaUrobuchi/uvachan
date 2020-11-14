#include <iostream>

int row[128], col[128];

int main()
{
	int n, m, i, mr, mc;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, mr=-1e6; i<n; i++)
		{
			scanf("%d", &row[i]);
			if (row[i] > mr)
			{
				mr = row[i];
			}
		}
		for (i=0, mc=-1e6; i<m; i++)
		{
			scanf("%d", &col[i]);
			if (col[i] > mc)
			{
				mc = col[i];
			}
		}
		if (mc == mr)
		{
			puts("possible");
		}
		else
		{
			puts("impossible");
		}
	}
	return 0;
}
