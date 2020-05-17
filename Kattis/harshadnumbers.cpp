#include <stdio.h>

int main()
{
	int n, i, j, k;
	while (scanf("%d", &n) == 1)
	{
		for (i=n; ; i++)
		{
			for (j=i, k=0; j; k+=j%10, j/=10);
			if (i % k == 0)
			{
				break;
			}
		}
		printf("%d\n", i);
	}
	return 0;
}