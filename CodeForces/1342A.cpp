#include <stdio.h>

int main()
{
	int count, x, y, a, b;
	long long ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &x, &y);
		scanf("%d%d", &a, &b);
		ans = 0;
		if (b < a+a)
		{
			if (x > 0 && y > 0)
			{
				if (x < y)
				{
					ans += (long long)x * b;
					y -= x;
					x = 0;
				}
				else
				{
					ans += (long long)y * b;
					x -= y;
					y = 0;
				}
			}
			else if (x < 0 && y < 0)
			{
				x = -x;
				y = -y;
				if (x < y)
				{
					ans += (long long)x * b;
					y -= x;
					x = 0;
				}
				else
				{
					ans += (long long)y * b;
					x -= y;
					y = 0;
				}
			}
		}
		if (x < 0)
		{
			x = -x;
		}
		if (y < 0)
		{
			y = -y;
		}
		ans += (long long)(x+y) * a;
		printf("%lld\n", ans);
	}
	return 0;
}
