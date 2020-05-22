#include <stdio.h>

int main()
{
	int a, b, p, q, r, s;
	while (scanf("%d%d%d%d", &p, &q, &r, &s) == 4)
	{
		a = p+q+r+s;
		scanf("%d%d%d%d", &p, &q, &r, &s);
		b = p+q+r+s;
		if (a > b)
		{
			puts("Gunnar");
		}
		else if (a == b)
		{
			puts("Tie");
		}
		else
		{
			puts("Emma");
		}
	}
	return 0;
}
