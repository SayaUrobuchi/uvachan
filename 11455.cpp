#include <stdio.h>

int main()
{
	int count, a, b, c, d;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(a == 0 || b == 0 || c == 0 || d == 0)
		{
			printf("banana\n");
		}
		else if(a == b && b == c && c == d)
		{
			printf("square\n");
		}
		else if((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
		{
			printf("rectangle\n");
		}
		else if((d < a+b+c) && (c < a+b+d) && (b < a+c+d) && (a < b+c+d))
		{
			printf("quadrangle\n");
		}
		else
		{
			printf("banana\n");
		}
	}
	return 0;
}
