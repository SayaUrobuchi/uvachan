#include <stdio.h>

char buf[65536];

int main()
{
	int n, m, i, j, k, ans, gg;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, ans=0; i<n; i++)
		{
			for (j=0, gg=0; j<m; j++)
			{
				scanf("%s", buf);
				for (k=1; buf[k]&&!gg; k++)
				{
					if (buf[k] >= 'A' && buf[k] <= 'Z')
					{
						gg = 1;
					}
				}
			}
			if (!gg)
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
