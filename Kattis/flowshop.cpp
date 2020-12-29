#include <iostream>

int ary[1024][1024];

int main()
{
	int n, m, i, j, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=m; j++)
			{
				scanf("%d", &t);
				ary[i][j] = std::max(ary[i-1][j], ary[i][j-1]) + t;
			}
			if (i != 1)
			{
				putchar(' ');
			}
			printf("%d", ary[i][m]);
		}
		puts("");
	}
	return 0;
}
