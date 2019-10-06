#include <stdio.h>

int main()
{
	int i, a;
	a = 2;
	for (i=0; i<25; i++)
	{
		a <<= 1;
		++a;
	}
	printf("%d\n", a);
	return 0;
}
