#include <stdio.h>

int main()
{
	int i, a, p, q;
	scanf("%d%d", &p, &q);
	a = 2;
	while (a % p)
	{
		a <<= 1;
		++a;
	}
	puts(a%q?"left":"right");
	return 0;
}
