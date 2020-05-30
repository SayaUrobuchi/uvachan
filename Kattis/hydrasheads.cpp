#include <stdio.h>

int main()
{
	int a, b, ans;
	while (scanf("%d%d", &a, &b) == 2)
	{
		if (a == 0 && b == 0)
		{
			break;
		}
		if ((a & 1) && b == 0)
		{
			puts("-1");
			continue;
		}
		ans = 0;
		if (b & 1)
		{
			++b;
			++ans;
		}
		ans += (b>>1);
		a += (b>>1);
		if (a & 1)
		{
			ans += 4;
		}
		ans += (a>>1);
		printf("%d\n", ans);
	}
	return 0;
}
