#include <stdio.h>

int ucnt, used[128];
int ary[128];

int main()
{
	int n, m, i, j, t;
	while (scanf("%d%d", &m, &n) == 2)
	{
		ary[0] = 0;
		ary[n+1] = m;
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		++ucnt;
		for (i=1; i<=n+1; i++)
		{
			for (j=0; j<i; j++)
			{
				t = ary[i]-ary[j];
				used[t] = ucnt;
			}
		}
		for (i=1, t=0; i<=m; i++)
		{
			if (used[i] == ucnt)
			{
				if (t)
				{
					putchar(' ');
				}
				++t;
				printf("%d", i);
			}
		}
		puts("");
	}
	return 0;
}
