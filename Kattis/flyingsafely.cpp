#include <stdio.h>

int main()
{
	int count, n, m;
	scanf("%d", &count);
	while (scanf("%d%d", &n, &m) == 2)
	{
		while (m--)
		{
			scanf("%*d%*d");
		}
		printf("%d\n", n-1);
	}
	return 0;
}
