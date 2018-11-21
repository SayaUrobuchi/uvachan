#include <stdio.h>

int main()
{
	int n, m;
	while(scanf("%d", &m) == 1)
	{
		while(m--)
		{
			scanf("%d", &n);
			if(n % 4 == 0 && (n % 100 || n % 400 == 0))
			{
				printf("a leap year\n");
			}
			else
			{
				printf("a normal year\n");
			}
		}
	}
	return 0;
}
