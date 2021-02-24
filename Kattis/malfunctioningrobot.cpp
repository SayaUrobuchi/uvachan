#include <iostream>

int main()
{
	int count, x, y, x0, x1, y0, y1;
	long long ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
		x = std::abs(x0-x1);
		y = std::abs(y0-y1);
		if (x < y)
		{
			std::swap(x, y);
		}
		ans = (long long)x + x - 1;
		if ((y&1) != ((x-1)&1))
		{
			++ans;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
