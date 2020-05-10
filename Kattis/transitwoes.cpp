#include <stdio.h>

int dis[1024];

int main()
{
	int i, n, t, r, ans, st, ed;
	while (scanf("%d%d%d%d", &st, &ed, &n, &ans) == 4)
	{
		ans += st;
		for (i=0; i<n; i++)
		{
			scanf("%d", &dis[i]);
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			dis[i] += t;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			r = ans % t;
			if (r)
			{
				ans += t-r;
			}
			ans += dis[i];
		}
		puts(ans<=ed ? "yes" : "no");
	}
	return 0;
}
