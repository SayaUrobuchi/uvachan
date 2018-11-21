#include <stdio.h>

int main()
{
	int count, a, b;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &a, &b);
		if(b % a)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d %d\n", a, b);
		}
	}
	return 0;
}
