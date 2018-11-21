#include <stdio.h>

int main()
{
	int n, m, i, ans;
	while (scanf("%d", &n) == 1)
	{
		ans = 0;
		for (i=0; i<5; i++)
		{
			scanf("%d", &m);
			if (n == m)
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
