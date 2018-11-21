#include <stdio.h>

int main()
{
	int n, m, s, i, j;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n < m)
		{
			s = 1;
		}
		else
		{
			s = -1;
		}
		for(i=n; i!=m; i+=s)
		{
			for(j=0; j<i; j++)
			{
				printf("*");
			}
			printf("\n");
		}
		for(j=0; j<i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
