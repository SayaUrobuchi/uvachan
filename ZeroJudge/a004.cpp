#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		if(!(n % 400) || (n % 100 && !(n % 4)))
		{
			printf("¶|¦~\n");
		}
		else
		{
			printf("¥­¦~\n");
		}
	}
	return 0;
}
