#include <stdio.h>

int main()
{
	int count, a, b, c;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (a+b == c || a-b == c || b-a == c || a*b == c || a*c == b || b*c == a)
		{
			puts("Possible");
		}
		else
		{
			puts("Impossible");
		}
	}
	return 0;
}
