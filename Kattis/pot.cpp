#include <stdio.h>

int main()
{
	int n, i, p, q, t, ans, j;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			p = t/10;
			q = t%10;
			for (j=0, t=1; j<q; j++, t*=p);
			ans += t;
		}
		printf("%d\n", ans);
	}
	return 0;
}
