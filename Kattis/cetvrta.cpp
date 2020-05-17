#include <stdio.h>

int main()
{
	int a, b, c, p, q, r, i, j;
	while (scanf("%d%d%d%d%d%d", &a, &p, &b, &q, &c, &r) == 6)
	{
		i = a;
		if (b != c && b != a)
		{
			i = b;
		}
		else if (c != b && c != a)
		{
			i = c;
		}
		j = p;
		if (q != p && q != r)
		{
			j = q;
		}
		else if (r != p && r != q)
		{
			j = r;
		}
		printf("%d %d\n", i, j);
	}
	return 0;
}
