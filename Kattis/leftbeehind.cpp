#include <stdio.h>

int main()
{
	int p, q;
	while (scanf("%d%d", &p, &q) == 2)
	{
		if (p == 0 && q == 0)
		{
			break;
		}
		if (p+q == 13)
		{
			puts("Never speak again.");
		}
		else if (p == q)
		{
			puts("Undecided.");
		}
		else if (p > q)
		{
			puts("To the convention.");
		}
		else
		{
			puts("Left beehind.");
		}
	}
	return 0;
}
