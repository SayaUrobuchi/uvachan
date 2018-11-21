#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", n>50?n-1:n);
	}
	return 0;
}
