#include <stdio.h>

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		printf("%d\n", m+(m-n));
	}
	return 0;
}
