#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", (85-n)%60);
	}
	return 0;
}
