#include <iostream>

int tbl[16384];

int main()
{
	int n, m, i, j, a, b, t, gg, ucnt;
	ucnt = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0)
		{
			break;
		}
		++ucnt;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			tbl[t] = ucnt;
		}
		for (i=0, gg=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			for (j=0; j<a; j++)
			{
				scanf("%d", &t);
				if (tbl[t] == ucnt)
				{
					--b;
				}
			}
			if (b > 0)
			{
				gg = 1;
			}
		}
		puts(gg?"no":"yes");
	}
	return 0;
}
