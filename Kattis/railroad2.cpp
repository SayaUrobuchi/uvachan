#include <stdio.h>

int main()
{
	int n;
	while (scanf("%*d%d", &n) == 1)
	{
		puts((n&1)?"impossible":"possible");
	}
	return 0;
}
