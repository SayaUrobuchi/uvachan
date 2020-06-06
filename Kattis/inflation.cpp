#include <stdio.h>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, i, gg;
	double best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0, best=2, gg=0; i<n; i++)
		{
			if (ary[i] > i+1)
			{
				gg = 1;
			}
			else if ((double)ary[i]/(i+1) < best)
			{
				best = (double)ary[i]/(i+1);
			}
		}
		if (gg)
		{
			puts("impossible");
		}
		else
		{
			printf("%.10lf\n", best);
		}
	}
	return 0;
}
