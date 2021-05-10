#include <iostream>

int main()
{
	int n, i, t, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=-(n-1); i<n; i++)
		{
			scanf("%d", &t);
			ans += t;
		}
		printf("%d\n", ans);
	}
	return 0;
}
