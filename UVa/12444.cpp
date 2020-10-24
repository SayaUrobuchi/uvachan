#include <stdio.h>

int main()
{
	int count, a, b, c, d, i, gg;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &c, &d);
		for (i=30, a=0, b=0, gg=0; i>=0; i--)
		{
			if (c & (1<<i))
			{
				if (!(d & (1<<i)))
				{
					gg = 1;
					break;
				}
				a |= (1<<i);
				b |= (1<<i);
			}
			else if (d & (1<<i))
			{
				if (b > a)
				{
					a |= (1<<i);
				}
				else
				{
					b |= (1<<i);
				}
			}
		}
		if (gg)
		{
			puts("-1");
		}
		else
		{
			printf("%d %d\n", a, b);
		}
	}
	return 0;
}
