#include <iostream>

int ary[1024], bry[1024];

int main()
{
	int n, i, j, sour, bitt, best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i], &bry[i]);
		}
		for (i=1, best=2e9; i<(1<<n); i++)
		{
			for (j=0, sour=1, bitt=0; j<n; j++)
			{
				if (i & (1<<j))
				{
					sour *= ary[j];
					bitt += bry[j];
				}
			}
			best = std::min(best, std::abs(sour-bitt));
		}
		printf("%d\n", best);
	}
	return 0;
}
