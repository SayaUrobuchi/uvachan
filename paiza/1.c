#include <stdio.h>

int main()
{
	int n, i, sum, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &t);
			sum += t;
		}
		printf("%d\n", sum);
	}
	return 0;
}
