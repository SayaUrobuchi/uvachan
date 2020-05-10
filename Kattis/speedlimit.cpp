#include <stdio.h>

int main()
{
	int n, i, ans, last, p, q;
	while (scanf("%d", &n) == 1)
	{
		if (n == -1)
		{
			break;
		}
		for (i=0, last=0, ans=0; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			ans += p * (q-last);
			last = q;
		}
		printf("%d miles\n", ans);
	}
	return 0;
}
