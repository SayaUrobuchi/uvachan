#include <iostream>

int main()
{
	int n, m, i, t, cur, best;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, cur=0, best=0; i<n; i++)
		{
			scanf("%d", &t);
			if (cur + t - m >= 0)
			{
				cur += t-m;
				if (cur > best)
				{
					best = cur;
				}
			}
			else
			{
				cur = 0;
			}
		}
		printf("%d\n", best);
	}
	return 0;
}
