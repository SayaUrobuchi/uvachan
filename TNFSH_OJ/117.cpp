#include <stdio.h>

int main()
{
	int n, i, ans, t;
	scanf("%d%d", &n, &ans);
	for (i=1; i<n; i++)
	{
		scanf("%d", &t);
		if (t > ans)
		{
			ans = t;
		}
	}
	printf("%d\n", ans);
	return 0;
}
