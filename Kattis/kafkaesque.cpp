#include <stdio.h>

int main()
{
	int n, i, t, ans, last;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=1, last=0; i<n; i++)
		{
			scanf("%d", &t);
			if (t < last)
			{
				++ans;
			}
			last = t;
		}
		printf("%d\n", ans);
	}
	return 0;
}
