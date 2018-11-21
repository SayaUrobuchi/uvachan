#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%s\n", (n&1)?"Odd":"Even");
	}
	return 0;
}
