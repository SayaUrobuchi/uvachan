#include <stdio.h>

int main()
{
	int count, n, m, i, d, t, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=0, t=0, ans=0; i<m; i++)
		{
			scanf("%d", &d);
			if (d >= 13 && (t+12)%7 == 5)
			{
				++ans;
			}
			t = (t+d)%7;
		}
		printf("%d\n", ans);
	}
	return 0;
}
