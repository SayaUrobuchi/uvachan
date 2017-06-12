#include <stdio.h>

#define M 16

char *ss[M] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
char nam[128][128];

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", nam[i]);
	}
	for (i=0, j=(n-1)/M+1; j>0; j--)
	{
		for (k=0; k<16; k++, i++)
		{
			printf("%s: %s\n", nam[i%n], ss[k]);
		}
	}
	return 0;
}
