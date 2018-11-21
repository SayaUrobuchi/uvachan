#include <stdio.h>

int main()
{
	int count, a, b, c, res;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &a, &b, &c);
		a += b;
		res = 0;
		while(a / c > 0)
		{
			res += a / c;
			a = a/c + a%c;
		}
		printf("%d\n", res);
	}
	return 0;
}
