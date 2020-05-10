#include <stdio.h>

int main()
{
	int n, i, t, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			if (t < 0)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
