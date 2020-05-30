#include <stdio.h>

int main()
{
	int a, b, c, d, e;
	while (scanf("%d%d%d%d%d", &a, &b, &c, &d, &e) == 5)
	{
		printf("%d\n", (b-a)*c/e+1+d);
	}
	return 0;
}
