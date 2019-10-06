#include <stdio.h>

char space[32], str[32][64];

int main()
{
	int n, i, j, k;
	for (i=0; i<32; i++)
	{
		space[i] = ' ';
	}
	space[31] = 0;
	for (i=0; i<26; i++)
	{
		for (j='A', k=0; j<='A'+i; j++, k++)
		{
			str[i][k] = j;
		}
		for (j-=2; j>='A'; j--, k++)
		{
			str[i][k] = j;
		}
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=0, j=n-1; i<n; i++, j--)
		{
			printf("%.*s%s\n", j, space, str[i]);
		}
		for (i=n-2, j=1; i>=0; i--, j++)
		{
			printf("%.*s%s\n", j, space, str[i]);
		}
	}
	return 0;
}
