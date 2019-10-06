#include <stdio.h>

int main()
{
	int i, a;
	a = 2;
	while (a % 71)
	{
		a <<= 1;
		++a;
	}
	puts(a%3?"left":"right");
	return 0;
}
