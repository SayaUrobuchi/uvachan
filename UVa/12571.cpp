#include <stdio.h>

int tbl[256];

int main()
{
	int count, n, m, i, j, t, ucnt, ans;
	ucnt = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		++ucnt;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			tbl[t&255] = ucnt;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			for (j=0, ans=0; j<256; j++)
			{
				if (tbl[j] == ucnt && (t & j) > ans)
				{
					ans = (t & j);
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
