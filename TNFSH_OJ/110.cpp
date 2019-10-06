#include <stdio.h>

char space[1024], star[1024];

int main()
{
	int count, i, j, k, n;
	for (i=0; i<1024; i++)
	{
		space[i] = ' ';
		star[i] = '*';
	}
	space[1023] = 0;
	star[1023] = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=1, j=n-1, k=n-3; k>0; i+=2, j--, k--)
		{
			printf("%.*s%.*s\n", j, space, i, star);
		}
		printf("%.*s\n", (n<<1)-1, star);
		printf(" %.*s\n", (n<<1)-3, star);
		printf("%.*s\n", (n<<1)-1, star);
		for (i-=2, j++, k=n-3; k>0; i-=2, j++, k--)
		{
			printf("%.*s%.*s\n", j, space, i, star);
		}
	}
	return 0;
}
