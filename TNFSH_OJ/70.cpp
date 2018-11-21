#include <stdio.h>

char s[128];

int main()
{
	double a, b, c, d, p, q, t;
	while (scanf("%lf%lf%s%lf%lf", &a, &b, s, &c, &d) == 5)
	{
		if (*s == '+')
		{
			p = a+c;
			q = b+d;
		}
		else if (*s == '-')
		{
			p = a-c;
			q = b-d;
		}
		else if (*s == '*')
		{
			p = a*c-b*d;
			q = a*d+b*c;
		}
		else if (*s == '/')
		{
			// 1 / (c+di)
			// => (c-di) / (c*c + d*d)
			// => c/(c*c+d*d) - d/(c*c+d*d)i
			t = c*c+d*d;
			p = a*c/t+b*d/t;
			q = a*-d/t+b*c/t;
		}
		printf("%.2f%+.2fi\n", p, q);
	}
	return 0;
}
