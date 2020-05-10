#include <stdio.h>

int main()
{
	int a, b, c, d, ans, v, t, i;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		v = a+b+c+d;
		ans = 1;
		for (i=2; i<=5; i++)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			t = a+b+c+d;
			if (t > v)
			{
				v = t;
				ans = i;
			}
		}
		printf("%d %d\n", ans, v);
	}
	return 0;
}
