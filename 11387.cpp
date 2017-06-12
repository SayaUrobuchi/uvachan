#include <stdio.h>

int main()
{
	int n, i, j;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		if(n % 2 || n == 2)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%d\n", (n / 2) * 3);
			for(i=1; i<n; i++)
			{
				printf("%d %d\n", i, i+1);
			}
			printf("%d %d\n", i, 1);
			for(i=1, j=n/2; i<=j; i++)
			{
				printf("%d %d\n", i, i+j);
			}
		}
	}
	return 0;
}
