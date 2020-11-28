#include <iostream>

char s[1024];

int main()
{
	int n;
	while (scanf("%d%s", &n, s) == 2)
	{
		for (; n>1; )
		{
			printf("%d bottles of %s on the wall, %d bottles of %s.\n", n, s, n, s);
			--n;
			printf((n==1?"Take one down, pass it around, %d bottle of %s on the wall.\n\n"
				  :"Take one down, pass it around, %d bottles of %s on the wall.\n\n"), n, s);
		}
		printf("1 bottle of %s on the wall, 1 bottle of %s.\n"
			"Take it down, pass it around, no more bottles of %s.\n", s, s, s);
	}
	return 0;
}
