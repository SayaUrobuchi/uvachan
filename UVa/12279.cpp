#include <stdio.h>

int main()
{
	int n, i, res, cas;
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		++cas;
		if (n == 0)
		{
			break;
		}
		res = 0;
		while (n--)
		{
			scanf("%d", &i);
			if (i > 0)
			{
				++res;
			}
			else
			{
				--res;
			}
		}
		printf("Case %d: %d\n", cas, res);
	}
	return 0;
}
