#include <stdio.h>

int main()
{
	int n, m, i, t, ans;
	while (scanf("%d%d", &m, &n) == 2)
	{
		ans = m * n + m;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			ans -= t;
		}
		printf("%d\n", ans);
	}
	return 0;
}
