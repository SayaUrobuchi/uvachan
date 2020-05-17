#include <stdio.h>

int main()
{
	int n, i, ans, best, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0, best=2147483647; i<n; i++)
		{
			scanf("%d", &t);
			if (t < best)
			{
				best = t;
				ans = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
