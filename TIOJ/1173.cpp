#include <stdio.h>

int main()
{
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if(b-a == c-b)
		{
			if(a && b && b*b == a*c)
			{
				printf("both\n");
			}
			else
			{
				printf("arithmetic\n");
			}
		}
		else if(a && b && b*b == a*c)
		{
			printf("geometric\n");
		}
		else
		{
			printf("normal\n");
		}
	}
	return 0;
}
