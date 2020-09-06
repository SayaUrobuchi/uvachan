#include <stdio.h>

const char *res[] = {"none", "one", "both"};

int main()
{
	int a, b, c, d, i, t, ans;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		for (i=0; i<3; i++)
		{
			scanf("%d", &t);
			--t;
			ans = 0;
			if (t % (a+b) < a)
			{
				++ans;
			}
			if (t % (c+d) < c)
			{
				++ans;
			}
			puts(res[ans]);
		}
	}
	return 0;
}
