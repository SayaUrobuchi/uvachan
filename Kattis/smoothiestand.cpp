#include <iostream>

int ary[1048576];

int main()
{
	int n, m, i, j, t;
	long long c, best;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0, best=-1; i<m; i++)
		{
			for (j=0, c=1e9; j<n; j++)
			{
				scanf("%d", &t);
				if (t > 0)
				{
					if (ary[j]/t < c)
					{
						c = ary[j] / t;
					}
				}
			}
			scanf("%d", &t);
			//printf("recipe %d make %d sell %d\n", i, t, c*t);
			if (c * t > best)
			{
				best = c*t;
			}
		}
		printf("%lld\n", best);
	}
	return 0;
}
