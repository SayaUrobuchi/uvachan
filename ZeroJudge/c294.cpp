#include <stdio.h>
#include <algorithm>

int ary[3];

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &ary[0], &ary[1], &ary[2]) == 3)
	{
		std::sort(ary, ary+3);
		a = ary[0];
		b = ary[1];
		c = ary[2];
		printf("%d %d %d\n", a, b, c);
		if (a+b <= c)
		{
			puts("No");
		}
		else if (a*a+b*b<c*c)
		{
			puts("Obtuse");
		}
		else if (a*a+b*b == c*c)
		{
			puts("Right");
		}
		else
		{
			puts("Acute");
		}
	}
	return 0;
}
