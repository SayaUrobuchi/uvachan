#include <stdio.h>

int tbl[1048576];

int main()
{
	int ucnt, n, max, min, gg, i, t;
	ucnt = 0;
	while (scanf("%d", &n) == 1)
	{
		ucnt++;
		scanf("%d", &min);
		max = min;
		tbl[min] = ucnt;
		gg = 0;
		for (i=1; i<n; i++)
		{
			scanf("%d", &t);
			if (t < min)
			{
				min = t;
			}
			if (t > max)
			{
				max = t;
			}
			if (tbl[t] == ucnt)
			{
				gg = 1;
			}
			tbl[t] = ucnt;
		}
		printf("%d %d %s\n", min, max, (!gg&&max-min==n-1)?"yes":"no");
	}
	return 0;
}
