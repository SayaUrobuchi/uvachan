#include <stdio.h>

int main()
{
	int n, res;
	while(scanf("%d", &n) == 1)
	{
		res = 0;
		while(n > 0)
		{
			res += n /= 5;
		}
		printf("%d\n", res);
	}
	return 0;
}
