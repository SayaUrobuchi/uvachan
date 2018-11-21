#include <stdio.h>

int tbl[10005];

int main()
{
	int cnt, n, m, i, k;
	cnt = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		++cnt;
		for (i=0; i<m; i++)
		{
			scanf("%d", &k);
			tbl[k] = cnt;
		}
		if (n == m)
		{
			puts("*");
			continue;
		}
		m = n-m;
		for (i=1; i<=n&&m; i++)
		{
			if (tbl[i] != cnt)
			{
				printf("%d ", i);
				--m;
			}
		}
		puts("");
	}
	return 0;
}
