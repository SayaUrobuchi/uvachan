#include <stdio.h>

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		puts(a+b ? "BUG FREE!" : "BARRIER BREACHED!");
	}
	return 0;
}
