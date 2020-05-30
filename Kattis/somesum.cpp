#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		n &= 3;
		if (n == 2)
		{
			puts("Odd");
		}
		else if (n == 0)
		{
			puts("Even");
		}
		else
		{
			puts("Either");
		}
	}
	return 0;
}
