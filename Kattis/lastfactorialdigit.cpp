#include <stdio.h>

int main()
{
	int count, n, i, ans;
	while (scanf("%d", &count) == 1)
	{
		while (count--)
		{
			scanf("%d", &n);
			for (i=2, ans=1; i<=n; i++)
			{
				ans *= i;
			}
			printf("%d\n", ans%10);
		}
	}
	return 0;
}
