#include <stdio.h>

int main()
{
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		printf("%d %d\n", a+c, b+d);
	}
	return 0;
}
