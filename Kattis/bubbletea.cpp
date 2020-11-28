#include <iostream>

int ary[1048576], bry[1048576];

int main()
{
	int n, m, o, i, j, k, t, best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		scanf("%d", &m);
		for (i=0; i<m; i++)
		{
			scanf("%d", &bry[i]);
		}
		for (i=0, best=2e9; i<n; i++)
		{
			scanf("%d", &t);
			for (j=0; j<t; j++)
			{
				scanf("%d", &k);
				if (ary[i] + bry[k-1] < best)
				{
					best = ary[i] + bry[k-1];
					//printf("?! %d\n", best);
				}
			}
		}
		scanf("%d", &o);
		printf("%d\n", std::max(0, o/best-1));
	}
	return 0;
}
