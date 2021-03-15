#include <iostream>

int main()
{
	int n, i, a, b;
	while (scanf("%d%d%d", &n, &a, &b) == 3)
	{
		for (i=0; n>=0&&n%a; i++, n-=b);
		if (n < 0)
		{
			puts("Impossible");
		}
		else
		{
			printf("%d %d\n", n/a, i);
		}
	}
	return 0;
}
