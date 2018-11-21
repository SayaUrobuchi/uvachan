#include <stdio.h>

int main()
{
	int n, i, sum, need, now, price;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d%d%d", &need, &now, &price);
			if (need > now)
			{
				sum += (need-now)*price;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
