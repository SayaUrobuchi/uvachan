#include <iostream>

int main()
{
	int m, x, y, p, q, mx, my;
	while (scanf("%d", &m) == 1)
	{
		if (m == 0)
		{
			break;
		}
		for (x=0, y=0, mx=0, my=0; ; )
		{
			scanf("%d%d", &p, &q);
			if (p == -1 && q == -1)
			{
				break;
			}
			if (x + p <= m)
			{
				x += p;
				if (q > y)
				{
					y = q;
				}
				if (x > mx)
				{
					mx = x;
				}
			}
			else
			{
				x = p;
				my += y;
				y = q;
				if (x > mx)
				{
					mx = x;
				}
			}
		}
		printf("%d x %d\n", mx, my+y);
	}
	return 0;
}
