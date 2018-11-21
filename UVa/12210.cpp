#include <stdio.h>

int main()
{
	int cas, n, m, i, t, res;
	cas = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		res = 64;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			if (t < res)
			{
				res = t;
			}
		}
		for (i=0; i<m; i++)
		{
			scanf("%*d");
		}
		if (n <= m)
		{
			printf("Case %d: 0\n", ++cas);
		}
		else
		{
			printf("Case %d: %d %d\n", ++cas, n-m, res);
		}
	}
	return 0;
}
