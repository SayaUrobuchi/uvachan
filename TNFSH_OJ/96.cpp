#include <stdio.h>

char op[1024];

int main()
{
	int a, b;
	while (scanf("%d%s%d", &a, op, &b) == 3)
	{
		if (*op == '+')
		{
			printf("%d %s %d = %d\n", a, op, b, a+b);
		}
		else if (*op == '-')
		{
			printf("%d %s %d = %d\n", a, op, b, a-b);
		}
		else if (*op == '*')
		{
			printf("%d %s %d = %d\n", a, op, b, a*b);
		}
		else
		{
			if (b)
			{
				printf("%d %s %d = %d ... %d\n", a, op, b, a/b, a%b);
			}
			else
			{
				puts("ERROR");
			}
		}
	}
	return 0;
}
