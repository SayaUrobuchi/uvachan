#include <stdio.h>

int main()
{
	int n;
	long long a, b, c, aa;
	while (scanf("%d", &n) == 1)
	{
		if (n <= 2)
		{
			puts("-1");
			continue;
		}
		a = n;
		aa = a * a;
		if (a & 1)
		{
			b = (aa>>1);
			c = b + 1;
		}
		else
		{
			b = (aa>>2) - 1;
			c = b + 2;
		}
		printf("%I64d %I64d\n", b, c);
	}
	return 0;
}
