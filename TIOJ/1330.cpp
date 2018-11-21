#include <stdio.h>

int main()
{
	int count, n;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%d\n", n%2);
	}
	return 0;
}
