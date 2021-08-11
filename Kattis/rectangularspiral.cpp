#include <iostream>

int main()
{
	int count, cas, x, y, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &cas, &x, &y);
		if (x < y)
		{
			printf("%d 2 %d %d\n", cas, x, y);
		}
		else if (y < 4)
		{
			printf("%d NO PATH\n", cas);
		}
		else
		{
			t = y - (x+2) - 1;
			printf("%d 6 1 2 3 %d %d %d\n", cas, 2-t, x+2, y-t);
		}
	}
	return 0;
}
