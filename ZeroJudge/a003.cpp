#include <stdio.h>

int main()
{
	int m, d;
	while(scanf("%d%d", &m, &d) == 2)
	{
		if((m+m+d) % 3 == 0)
		{
			printf("´¶³q\n");
		}
		else if((m+m+d) % 3 == 1)
		{
			printf("¦N\n");
		}
		else
		{
			printf("¤j¦N\n");
		}
	}
	return 0;
}
