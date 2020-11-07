#include <iostream>

int main()
{
	int count, n, i, sum, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, sum=-(n-1); i<n; i++)
		{
			scanf("%d", &t);
			sum += t;
		}
		printf("%d\n", sum);
	}
	return 0;
}
