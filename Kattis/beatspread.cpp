#include <iostream>

int main()
{
	int count, a, b;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &a, &b);
		if (((a+b)&1) || a < b)
		{
			puts("impossible");
		}
		else
		{
			printf("%d %d\n", (a+b)/2, (a-b)/2);
		}
	}
	return 0;
}
