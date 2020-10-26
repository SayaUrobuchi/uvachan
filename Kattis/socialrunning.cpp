#include <iostream>

int ary[1048576];

int main()
{
	int n, i, t, best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0, best=1e8; i<n; i++)
		{
			t = ary[i] + ary[(i+2)%n];
			if (t < best)
			{
				best = t;
			}
		}
		printf("%d\n", best);
	}
	return 0;
}
