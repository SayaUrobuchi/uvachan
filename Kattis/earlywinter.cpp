#include <iostream>

int main()
{
	int n, m, i, a, b, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, a=0, b=1; i<n; i++)
		{
			scanf("%d", &t);
			if (t <= m)
			{
				b = 0;
			}
			else if (b)
			{
				++a;
			}
		}
		if (b)
		{
			puts("It had never snowed this early!");
		}
		else
		{
			printf("It hadn't snowed this early in %d years!\n", a);
		}
	}
	return 0;
}
