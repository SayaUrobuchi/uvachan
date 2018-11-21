#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		if(n % 4 == 0 && (n % 100 || n % 400 == 0))
		{
			printf("a leap year\n");
		}
		else
		{
			printf("a normal year\n");
		}
	}
	return 0;
}
