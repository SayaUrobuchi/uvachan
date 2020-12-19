#include <iostream>

int ary[1048576];

int main()
{
	int n, m, i, j, t, u, best;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0, best=0; i<n; i++)
		{
			for (j=i, t=0, u=0; j<n; j++)
			{
				if (t + ary[j] <= m)
				{
					t += ary[j];
					++u;
				}
			}
			best = std::max(best, u);
		}
		printf("%d\n", best);
	}
	return 0;
}
