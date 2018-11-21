#include <stdio.h>

int main()
{
	int n, i, j, k;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		printf("Printing order for %d pages:\n", n);
		j = n / 4;
		j *= 4;
		if(j != n)
		{
			j += 4;
		}
		for(i=1, k=1; i<j; i++, j--, k++)
		{
			if(j > n)
			{
				printf("Sheet %d, front: Blank, %d\n", k, i);
			}
			else
			{
				printf("Sheet %d, front: %d, %d\n", k, j, i);
			}
			i++;
			j--;
			if(j > n)
			{
				if(i <= n)
				{
					printf("Sheet %d, back : %d, Blank\n", k, i);
				}
			}
			else
			{
				if(i <= n)
				{
					printf("Sheet %d, back : %d, %d\n", k, i, j);
				}
				else
				{
					printf("Sheet %d, back : Blank, %d\n", k, j);
				}
			}
		}
	}
	return 0;
}
