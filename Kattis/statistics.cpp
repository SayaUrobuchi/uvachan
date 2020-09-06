#include <stdio.h>

int main()
{
	int cas, n, i, small, large, t;
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, small=2147483647, large=-2147483647; i<n; i++)
		{
			scanf("%d", &t);
			if (t < small)
			{
				small = t;
			}
			if (t > large)
			{
				large = t;
			}
		}
		printf("Case %d: %d %d %d\n", ++cas, small, large, large-small);
	}
	return 0;
}
