#include <stdio.h>

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		puts((b+c)%(a<<1) < a ? "paul" : "opponent");
	}
	return 0;
}
