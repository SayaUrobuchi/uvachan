#include <stdio.h>

int ucnt, used[16];

int main()
{
	int a, b, i, t, ans;
	while (scanf("%d%d", &a, &b) == 2)
	{
		for (i=a, ans=0; i<=b; i++)
		{
			t = i;
			ucnt++;
			for (; t; t/=10)
			{
				if (!(t%10) || used[t%10] == ucnt || i % (t%10))
				{
					break;
				}
				used[t%10] = ucnt;
			}
			if (!t)
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
