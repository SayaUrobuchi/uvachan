#include <stdio.h>

const int M = 42;

int tbl[M];

int main()
{
	int t, ans, ucnt, i;
	ucnt = 0;
	while (scanf("%d", &t) == 1)
	{
		++ucnt;
		ans = 1;
		tbl[t%M] = ucnt;
		for (i=1; i<10; i++)
		{
			scanf("%d", &t);
			if (tbl[t%M] != ucnt)
			{
				tbl[t%M] = ucnt;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
