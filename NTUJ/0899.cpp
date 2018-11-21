#include <stdio.h>

int main()
{
	int count, a, b;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", a+b);
	}
	return 0;
}
