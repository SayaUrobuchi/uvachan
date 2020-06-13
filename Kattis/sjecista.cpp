#include <stdio.h>

int main()
{
	int n, a, b, c;
	while (scanf("%d", &n) == 1)
	{
		for (a=1, b=n-3, c=0; b>=1; a++, b--)
		{
			c += a*b;
		}
		printf("%d\n", (c*n)>>2);
	}
	return 0;
}
