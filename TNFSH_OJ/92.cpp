#include <stdio.h>

char a[1024], b[1024], c[1024];

int main()
{
	while (scanf("%s%s%s", a, b, c) == 3)
	{
		printf("Hello, %s, %s, and %s!\n", a, b, c);
	}
	return 0;
}
