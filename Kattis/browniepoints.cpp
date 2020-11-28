#include <iostream>

int px[32768], py[32768];

int main()
{
	int n, i, x, y, a, b;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		x = px[n>>1];
		y = py[n>>1];
		for (i=0, a=0, b=0; i<n; i++)
		{
			if (px[i] != x && py[i] != y)
			{
				if ((px[i] > x && py[i] > y) || (px[i] < x && py[i] < y))
				{
					++a;
				}
				else
				{
					++b;
				}
			}
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}
