#include <stdio.h>

int main()
{
	int count, i, ans, last, t;
	scanf("%d", &count);
	while (count--)
	{
		for (i=0, ans=0; ; i++)
		{
			scanf("%d", &t);
			if (!t)
			{
				break;
			}
			if (i)
			{
				if (t > (last<<1))
				{
					ans += t-(last<<1);
				}
			}
			last = t;
		}
		printf("%d\n", ans);
	}
	return 0;
}
