#include <stdio.h>

int main()
{
	int n, i, p, q;
	while (scanf("%d%d%d", &p, &q, &n) == 3)
	{
		for (i=1; i<=n; i++)
		{
			if (i%p == 0 && i%q == 0)
			{
				puts("FizzBuzz");
			}
			else if (i%p == 0)
			{
				puts("Fizz");
			}
			else if (i%q == 0)
			{
				puts("Buzz");
			}
			else
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
