#include <stdio.h>

int main()
{
	int count, n, i, t, last, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &last);
		for (i=1; i<n; i++)
		{
			scanf("%d", &t);
			if (t != last+1)
			{
				ans = i+1;
			}
			else
			{
				last = t;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
