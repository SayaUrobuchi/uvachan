#include <stdio.h>

char op[1024];

int main()
{
	double a, b;
	while (scanf("%lf%s%lf", &a, op, &b) == 3)
	{
		if (*op == '+')
		{
			printf("%.4f %s %.4f = %.4f\n", a, op, b, a+b);
		}
		else if (*op == '-')
		{
			printf("%.4f %s %.4f = %.4f\n", a, op, b, a-b);
		}
		else if (*op == '*')
		{
			printf("%.4f %s %.4f = %.4f\n", a, op, b, a*b);
		}
		else if (*op == '/')
		{
			if (b == 0)
			{
				puts("ERROR");
			}
			else
			{
				printf("%.4f %s %.4f = %.4f\n", a, op, b, a/b);
			}
		}
	}
	return 0;
}
