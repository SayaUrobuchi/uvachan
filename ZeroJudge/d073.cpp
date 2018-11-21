#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", (n-1)/3+1);
	}
	return 0;
}
