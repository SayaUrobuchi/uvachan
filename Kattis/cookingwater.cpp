#include <iostream>

int main()
{
	int n, i, a, b, p, q;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, a=-1, b=1048576; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			if (p > a)
			{
				a = p;
			}
			if (q < b)
			{
				b = q;
			}
		}
		if (a <= b)
		{
			puts("gunilla has a point");
		}
		else
		{
			puts("edward is right");
		}
	}
	return 0;
}
