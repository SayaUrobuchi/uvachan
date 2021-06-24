#include <iostream>

int main()
{
	int n, i, k, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d", &k);
			if (k > 10)
			{
				ans += k-10;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
