#include <stdio.h>

int ary[128];

int main()
{
	int n, i, t, ans, best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0, best=1048576; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if (i >= 2)
			{
				t = ary[i]>ary[i-2]?ary[i]:ary[i-2];
				if (t < best)
				{
					best = t;
					ans = i-1;
				}
			}
		}
		printf("%d %d\n", ans, best);
	}
	return 0;
}
