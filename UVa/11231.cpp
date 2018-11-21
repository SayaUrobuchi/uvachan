#include <stdio.h>

int main()
{
	int n, m, c;
	while(scanf("%d%d%d", &n, &m, &c) == 3)
	{
		if(!(n + m + c))
		{
			break;
		}
		n -= 7;
		n *= m - 7;
		if(c)
		{
			printf("%d\n", n / 2 + (n % 2));
		}
		else
		{
			printf("%d\n", n / 2);
		}
	}
	return 0;
}
