#include <stdio.h>

int main()
{
	int count, cas, n;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &cas, &n);
		printf("%d %d\n", cas, n+(n+1)*n/2);
	}
	return 0;
}
