#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		printf("%d\n", n>3?n-2:1);
	}
	return 0;
}
