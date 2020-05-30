#include <stdio.h>

int main()
{
	int count, n;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		printf("%d\n", n?(n-1)/400+1:0);
	}
	return 0;
}
