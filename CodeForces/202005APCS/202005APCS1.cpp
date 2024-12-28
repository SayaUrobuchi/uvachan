#include <stdio.h>

int main()
{
	int n, i, t, a, pos, x, y;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, t=0, pos=0; i<n; i++)
		{
			scanf("%d", &a);
			if (a == 0)
			{
				t++;
			}
			else if (a & 1)
			{
				pos -= a;
			}
			else
			{
				pos += a;
			}
		}
		x = pos - t*5;
		y = pos + t*6;
		printf("%d %d %d\n", x, y, y-x);
	}
	return 0;
}
