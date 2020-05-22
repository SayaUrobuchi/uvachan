#include <stdio.h>

int fib[64];

int main()
{
	int n, i;
	fib[1] = 1;
	for (i=2; i<=45; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	while (scanf("%d", &n) == 1)
	{
		printf("%d %d\n", fib[n-1], fib[n]);
	}
	return 0;
}
