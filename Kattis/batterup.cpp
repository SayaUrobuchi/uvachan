#include <stdio.h>

int main()
{
	int n, i, m, ans, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0, m=0; i<n; i++)
		{
			scanf("%d", &t);
			if (t >= 0)
			{
				m++;
				ans += t;
			}
		}
		printf("%g\n", ans/(double)m);
	}
	return 0;
}
