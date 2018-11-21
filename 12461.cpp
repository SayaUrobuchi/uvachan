#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		puts("1/2");
	}
	return 0;
}
