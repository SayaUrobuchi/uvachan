#include <iostream>

int main()
{
	int n, m, p, q, i, j, t, u, ans;
	while (scanf("%d%d%d%d", &n, &m, &p, &q) == 4)
	{
		for (i=0, ans=-1; i<p; i++)
		{
			scanf("%d", &t);
			for (j=0; j<q; j++)
			{
				scanf("%d", &u);
				if (u >= n)
				{
					if (ans == -1 || ans > t*n)
					{
						ans = t*n;
					}
				}
			}
		}
		if (ans == -1 || ans > m)
		{
			puts("stay home");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
