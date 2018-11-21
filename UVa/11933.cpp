#include <stdio.h>

int main()
{
	int n, i, j;
	int a[2];
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		a[0] = a[1] = 0;
		for (i=0, j=0; i<31; i++)
		{
			if (n & (1<<i))
			{
				a[j] |= (1<<i);
				j = 1-j;
			}
		}
		printf("%d %d\n", a[0], a[1]);
	}
	return 0;
}
