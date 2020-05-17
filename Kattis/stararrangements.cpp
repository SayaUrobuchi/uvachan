#include <stdio.h>

int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		printf("%d:\n", n);
		for (i=2; i<n; i++)
		{
			for (j=i-1; j<=i; j++)
			{
				if (n % (i+j) == 0 || (n-i) % (i+j) == 0)
				{
					printf("%d,%d\n", i, j);
				}
			}
		}
	}
	return 0;
}
