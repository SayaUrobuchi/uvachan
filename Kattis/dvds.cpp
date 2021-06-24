#include <iostream>

int main()
{
	int count, n, i, j, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, j=1; i<n; i++)
		{
			scanf("%d", &t);
			if (t == j)
			{
				++j;
			}
		}
		printf("%d\n", n-j+1);
	}
	return 0;
}
