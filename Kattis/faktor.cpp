#include <stdio.h>

int main()
{
	int p, q;
	while (scanf("%d%d", &p, &q) == 2)
	{
		printf("%d\n", p*(q-1)+1);
	}
	return 0;
}
