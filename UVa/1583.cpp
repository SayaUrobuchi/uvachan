#include <stdio.h>

int main()
{
	int count, n, i, j, k;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		i = n-9*6;
		if (i <= 0)
		{
			i = 1;
		}
		for (; i<n; i++)
		{
			j = i;
			k = j;
			for (; j; j/=10)
			{
				k += j%10;
			}
			if (k == n)
			{
				break;
			}
		}
		if (i < n)
		{
			printf("%d\n", i);
		}
		else
		{
			puts("0");
		}
	}
	return 0;
}
