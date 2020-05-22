#include <stdio.h>

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		printf("%d %d / %d\n", n/m, n%m, m);
	}
	return 0;
}
