#include <stdio.h>

int main()
{
	int n, in, space;
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		space = 0;
		while(n--)
		{
			scanf("%d", &in);
			if(in)
			{
				if(space)
				{
					printf(" ");
				}
				space = 1;
				printf("%d", in);
			}
		}
		if(!space)
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
