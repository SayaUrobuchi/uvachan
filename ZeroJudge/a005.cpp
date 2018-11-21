#include <stdio.h>

int main()
{
	int count, a, b, c, d;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(d-c == c-b && c-b == b-a)
		{
			printf("%d %d %d %d %d\n", a, b, c, d, d+d-c);
		}
		else
		{
			printf("%d %d %d %d %d\n", a, b, c, d, d*(d/c));
		}
	}
	return 0;
}
