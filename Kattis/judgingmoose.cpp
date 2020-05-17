#include <stdio.h>

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			puts("Not a moose");
		}
		else if (n == m)
		{
			printf("Even %d\n", n+m);
		}
		else
		{
			printf("Odd %d\n", n>m?n<<1:m<<1);
		}
	}
	return 0;
}