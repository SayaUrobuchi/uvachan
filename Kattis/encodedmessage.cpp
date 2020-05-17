#include <stdio.h>

char tbl[256][256];
char s[32768];

int main()
{
	int count, n, i, j, k, len;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		for (len=0; s[len]; len++);
		for (n=1; n*n<len; n++);
		for (j=0, k=0; j<n; j++)
		{
			for (i=n-1; i>=0; i--)
			{
				tbl[i][j] = s[k++];
			}
		}
		for (i=0; i<n; i++)
		{
			printf("%.*s", n, tbl[i]);
		}
		puts("");
	}
	return 0;
}