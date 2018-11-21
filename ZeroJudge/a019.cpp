#include <stdio.h>

char str[100];

int main()
{
	int n, i;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; n; i++, n>>=1)
		{
			str[i] = n % 2;
		}
		for(i--; i>-1; i--)
		{
			printf("%d", str[i]);
		}
		printf("\n");
	}
	return 0;
}
