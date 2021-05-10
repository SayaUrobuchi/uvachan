#include <iostream>

int main()
{
	int n, i, t, ans, last;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			if (i & 1)
			{
				ans += t-last;
			}
			else
			{
				last = t;
			}
		}
		if (n & 1)
		{
			puts("still running");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
