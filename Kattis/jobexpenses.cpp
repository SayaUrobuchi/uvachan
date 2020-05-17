#include <stdio.h>

int main()
{
	int n, i, ans, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			if (t < 0)
			{
				ans -= t;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}