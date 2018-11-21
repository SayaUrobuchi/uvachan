#include <stdio.h>

int ary[1048576], pot[1048576];

int main()
{
	int n, m, i,j, w, x, ans;
	while (scanf("%d", &n) == 1)
	{
		m = (1<<n);
		for (i=0; i<m; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0; i<m; i++)
		{
			w = 0;
			for (j=0; j<n; j++)
			{
				w += ary[i^(1<<j)];
			}
			pot[i] = w;
		}
		ans = 0;
		for (i=0; i<m; i++)
		{
			w = 0;
			for (j=0; j<n; j++)
			{
				x = pot[i^(1<<j)];
				if (x > w)
				{
					w = x;
				}
			}
			w += pot[i];
			if (w > ans)
			{
				ans = w;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
