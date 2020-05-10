#include <stdio.h>

int main()
{
	int count, a, b, c;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &a, &b, &c);
		b -= c;
		if (a == b)
		{
			puts("does not matter");
		}
		else if (a < b)
		{
			puts("advertise");
		}
		else
		{
			puts("do not advertise");
		}
	}
	return 0;
}
