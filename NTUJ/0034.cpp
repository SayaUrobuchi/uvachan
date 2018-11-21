#include <stdio.h>

int main()
{
	int count, n, m;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		printf("%d\n", n>m?n:m);
	}
	return 0;
}
