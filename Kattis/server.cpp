#include <iostream>

int main()
{
	int n, m, i, a, b, t, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, a=0, b=1, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			if (b && a + t <= m)
			{
				a += t;
				++ans;
			}
			else
			{
				b = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
