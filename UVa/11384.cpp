#include <stdio.h>

int main()
{
	int n, res;
	while (scanf("%d", &n) == 1)
	{
		res = 0;
		while (n)
		{
			n >>= 1;
			res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
