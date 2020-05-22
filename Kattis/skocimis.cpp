#include <stdio.h>

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		printf("%d\n", (c-b>b-a?c-b:b-a)-1);
	}
	return 0;
}