#include <iostream>

int main()
{
	int n, i, last, ans, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, last=1e9, ans=1; i<n; i++)
		{
			scanf("%d", &t);
			if (t > last)
			{
				++ans;
			}
			last = t;
		}
		printf("%d\n", ans);
	}
	return 0;
}
