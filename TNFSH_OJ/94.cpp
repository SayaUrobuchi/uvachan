#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (n <= 2)
		{
			puts("Winter!");
		}
		else if (n <= 5)
		{
			puts("Spring!");
		}
		else if (n <= 8)
		{
			puts("Summer!");
		}
		else if (n <= 11)
		{
			puts("Autumn!");
		}
		else
		{
			puts("Winter!");
		}
	}
	return 0;
}
